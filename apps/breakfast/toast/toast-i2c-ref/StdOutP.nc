/*
    StdOut module - module that buffers and perhaps eventually will do some
    printf like thing.
    Copyright (C) 2002 Mads Bondo Dydensborg <madsdyd@diku.dk>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
/*
 * Simple StdOut component, uses Uart interface, buffers into 200 uint8_t buffer
 */

/**
 * Simple StdOut component that uses Uart interface.
 * <p>This configuration maps onto the uart that is normally used to connect onto 
 * a pc.</p>
 *
 * <p>Please note that this component blocks interrupts and copies
 * data - it is not a very good TinyOS citizen. Its a debug tool.</p>
 */
module StdOutP
{
  provides interface StdControl;
  provides interface StdOut;
  uses interface StdControl as SerialControl;
  uses interface UartStream;
//    call UART.put(*bufferhead);

}

#define STDOUT_BUFFER_SIZE 2002 // This will probably not be enough always.

// Use the leds to print
//#define DEBUG

implementation
{
  /** The buffer used to buffer into. This is 200 bytes */
  uint8_t buffer[STDOUT_BUFFER_SIZE];
  uint8_t * bufferhead;
  uint8_t * buffertail;
  uint8_t * bufferend;
  uint8_t * bufferstart;

  bool notOutputting; 
  
  /* StdControl */
  command error_t StdControl.start()
  {
    atomic {
      bufferhead   = buffer;
      buffertail   = buffer;
      bufferstart  = buffer;
      bufferend    = buffer + STDOUT_BUFFER_SIZE - 1;

      notOutputting = TRUE;
    }

    call SerialControl.start();

    return SUCCESS;
  }

  command error_t StdControl.stop()
  {
    call SerialControl.stop();

    return SUCCESS;
  }
  
  command error_t StdOut.done() {
    return SUCCESS;
  }

  /* Add a string to the circular buffer. The string must be null-terminated.
     The number of chars written will be returned (not including the trailing \0).
  */
  async command uint16_t StdOut.print(const char * str) 
  {
    uint16_t retcount = 0;

    atomic 
    {

      if (buffertail >= bufferhead)
      {
        while ( (buffertail < bufferend) && (*str != 0) )
        {
          *buffertail = *str;
          buffertail++;
          str++;
          retcount++;
        }

        if ( (buffertail == bufferend) )
        {
          buffertail = bufferstart;
        }
      }

      while ( (buffertail < bufferhead) && (*str != 0) )
      {
        *buffertail = *str;
        buffertail++;
        str++;
        retcount++;
      }

      if (notOutputting)
      {
        notOutputting = FALSE;

        if (bufferhead < buffertail)
        {
          call UartStream.send(bufferhead, buffertail-bufferhead);
        } else {
          call UartStream.send(bufferhead, bufferend-bufferhead);
        }
      }
    }
    
    return retcount;
  }

  /* Handle emptying the buffer - the one in head have now been outputted 
     and we need to output the next, if needed. */
  async event void UartStream.sendDone( uint8_t * buf, uint16_t len, error_t error ) 
  {
    atomic 
    {
      bufferhead += len;
      
      if (bufferhead >= bufferend)
      {
        bufferhead = bufferstart;
      }

      if (bufferhead < buffertail)
      {
        call UartStream.send(bufferhead, buffertail-bufferhead);
      } 
      else if (bufferhead > buffertail) 
      {
        call UartStream.send(bufferhead, bufferend-bufferhead);
      } 
      else 
      {
        notOutputting = TRUE;    
      }
    }
  }


  /* Handle getting data such that the user of this interface can get data. */
  async event void UartStream.receivedByte(uint8_t data) 
  {
    signal StdOut.get(data);
  }

  async event void UartStream.receiveDone( uint8_t* buf, uint16_t len, error_t error ) {
  }

  default async event void StdOut.get(uint8_t data) {
  }

  /* Add a hex number to the circular buffer 
     - code is meant to be easy to read */
  async command uint8_t StdOut.printHex(uint8_t c) {
    char str[3];
    uint8_t v;
    
    /* Left digit */
    v = (0xF0U & c) >> 4;
    if (v < 0xAU) {
      str[0] = v + '0';
    } else {
      str[0] = v - 0xAU + 'A';
    }
    
    /* Right digit */
    v = (0xFU & c);
    if (v < 0xAU) {
      str[1] = v + '0';
    } else {
      str[1] = v - 0xAU + 'A';
    }
    str[2] = 0;
    
    return call StdOut.print(str);
  }

  /* Add a word number to the circular buffer as hex
     - code is meant to be easy to read */
  async command uint8_t StdOut.printHexword(uint16_t c) {
    return call StdOut.printHex((0xFF00U & c) >> 8) 
      + call StdOut.printHex(0xFFU & c);
  }

  /* Add a long number to the circular buffer as hex
     - code is meant to be easy to read */
  async command uint8_t StdOut.printHexlong(uint32_t c) {
    return call StdOut.printHex((0xFF000000U & c) >> 24) 
      + call StdOut.printHex((0xFF0000U & c) >> 16) 
      + call StdOut.printHex((0xFF00U & c) >> 8) 
      + call StdOut.printHex(0xFFU & c);
  }

	/* Add a uint8_t base10 number to the circular buffer */
  async command uint8_t StdOut.printBase10uint8(const uint8_t c)
	{
		bool print = 0;
		char str[4];
		uint8_t idx = 0, tmp;
		uint32_t v;
		
		v = c;

		// Digit 10^2
		tmp = v / 100;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 100;
			print = 1;
		}

		// Digit 10^1
		tmp = v / 10;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 10;
			print = 1;
		}

		// Digit 10^0
		str[idx] = v + 48;
		idx++;
   
      		str[idx] = 0;
   		
		return call StdOut.print(str);
	}

	/* Add a uint8_t base10 number to the circular buffer */
  async command uint8_t StdOut.printBase10int8(const int8_t c)
	{
		uint8_t counter = 0, v;
		
		if (c < 0) {
			counter = call StdOut.print("-");
			v = -1 * c; 
		} else {
			v = (uint8_t) c;
		}

		counter += call StdOut.printBase10uint8(v);
		
		return counter;
	}

	/* Add a uint16_t base10 number to the circular buffer */
  async command uint8_t StdOut.printBase10uint16(const uint16_t c)
	{
		bool print = 0;
		char str[6];
		uint8_t idx = 0, tmp;
		uint32_t v;
		
		v = c;

		// Digit 10^4
		tmp = v / 10000;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 10000;
			print = 1;
		}
		
		// Digit 10^3
		tmp = v / 1000;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 1000;
			print = 1;
		}

		// Digit 10^2
		tmp = v / 100;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 100;
			print = 1;
		}

		// Digit 10^1
		tmp = v / 10;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 10;
			print = 1;
		}

		// Digit 10^0
		str[idx] = v + 48;
		idx++;
   
      		str[idx] = 0;

		return call StdOut.print(str);
	}
  
	/* Add a uint16_t base10 number to the circular buffer */
  async command uint8_t StdOut.printBase10int16(const int16_t c)
	{
		uint8_t counter = 0;
		uint16_t v;
		
		if (c < 0) {
			counter = call StdOut.print("-");
			v = -1 * c; 
		} else {
			v = (uint16_t) c;
		}

		counter += call StdOut.printBase10uint16(v);
		
		return counter;
	}

	/* Add a uint32_t base10 number to the circular buffer */
  async command uint8_t StdOut.printBase10uint32(const uint32_t c)
	{
		bool print = 0;
		char str[11];
		uint8_t idx = 0, tmp;
		uint32_t v;
		
		v = c;
    
		// Digit 10^9
		tmp = v / 1000000000;
		if (tmp != 0) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 1000000000;
			print = 1;
		}
				
		// Digit 10^8
		tmp = v / 100000000;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 100000000;
			print = 1;
		}

		// Digit 10^7
		tmp = v / 10000000;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 10000000;
			print = 1;
		}
		
		// Digit 10^6
		tmp = v / 1000000;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 1000000;
			print = 1;
		}
		
		// Digit 10^5
		tmp = v / 100000;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 100000;
			print = 1;
		}
		
		// Digit 10^4
		tmp = v / 10000;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 10000;
			print = 1;
		}
		
		// Digit 10^3
		tmp = v / 1000;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 1000;
			print = 1;
		}

		// Digit 10^2
		tmp = v / 100;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 100;
			print = 1;
		}

		// Digit 10^1
		tmp = v / 10;
		if (tmp != 0 || print) {
			str[idx] = tmp + 48;
			idx++;
			v = v % 10;
			print = 1;
		}

		// Digit 10^0
		str[idx] = v + 48;
		idx++;
   
      		str[idx] = 0;

		return call StdOut.print(str);
	}

	/* Add a uint32_t base10 number to the circular buffer */
  async command uint8_t StdOut.printBase10int32(const int32_t c)
	{
		uint8_t counter = 0;
		uint32_t v;
		
		if (c < 0) {
			counter = call StdOut.print("-");
			v = -1 * c; 
		} else {
			v = (uint32_t) c;
		}

		counter += call StdOut.printBase10uint32(v);
		
		return counter;
	}

  /* Add a float base10 number to the circular buffer */
  async command uint8_t StdOut.printBase10float(const float c)
  {
    uint8_t counter = 0;
    
    float tmp;
    uint16_t first;
    uint16_t second;
    
    if (c < 0)
    {
      tmp = -1.0 * c;
      
      counter += call StdOut.print("-");

    } else {
      tmp = c;
    }

    first = floor(c);
    second = floor((c - first) * 100);

    counter += call StdOut.printBase10uint16(first);  
    counter += call StdOut.print(".");
    
    if (second < 10)
    {
      counter += call StdOut.print("0");
      counter += call StdOut.printBase10uint16(second);  
    } else {
      counter += call StdOut.printBase10uint16(second);  
    }
    
    return counter;
  }

	/* Add a 8-bit base2 number to the circular buffer */
  async command uint8_t StdOut.printBase2uint8(uint8_t c)
	{
	    char str[9];
		uint8_t i, v;
		
		v = c;
		
		for (i = 0; i < 8; i++) 
		{
			str[7 - i] = ((v & 0x01U) == 0x01U) ? '1' : '0';
			v >>= 1;
		}
		
		str[8] = 0;

		return call StdOut.print(str);
	}

	/* Add a 16-bit base2 number to the circular buffer */
  async command uint8_t StdOut.printBase2uint16(uint16_t c)
	{
	    char str[17];
		uint8_t i;
		uint16_t v;
		
		v = c;
		
		for (i = 0; i < 16; i++) 
		{
			str[15 - i] = ((v & 0x0001U) == 0x0001U) ? '1' : '0';
			v >>= 1;
		}
		
		str[16] = 0;

		return call StdOut.print(str);
	}

	/* Add a 32-bit base10 number to the circular buffer */
  async command uint8_t StdOut.printBase2uint32(uint32_t c)
	{
	    char str[33];
		uint8_t i;
		uint32_t v;
		
		v = c;
		
		for (i = 0; i < 32; i++) 
		{
			str[31 - i] = ((v & 0x00000001U) == 0x00000001U) ? '1' : '0';
			v >>= 1;
		}
		
		str[32] = 0;

		return call StdOut.print(str);
	}

  /** Dump an array of hex's
   * 
   * \param ptr - array of uint8_t values
   * \param count - count of values in array
   * \param sep - optional seperator string

   * Always return succes, even if something went wrong.
   */
  async command void StdOut.dumpHex(uint8_t ptr[], uint8_t countar, uint8_t * sep) {
    int i;
    for (i = 0; i < countar; i++) {
      if (i != 0) { 
	call StdOut.print(sep);
      }
      call StdOut.printHex(ptr[i]);
    }
  }
  
}
