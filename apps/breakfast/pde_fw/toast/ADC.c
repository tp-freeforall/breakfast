//******************************************************************************
//  MSP430x24x Demo - ADC12, Repeated Sequence of Conversions
//
//  Description: This example shows how to perform a repeated sequence of
//  conversions using "repeat sequence-of-channels" mode.  AVcc is used for the
//  reference and repeated sequence of conversions is performed on Channels A0,
//  A1, A2, and A3. Each conversion result is stored in ADC12MEM0, ADC12MEM1,
//  ADC12MEM2, and ADC12MEM3 respectively. After each sequence, the 4 conversion
//  results are moved to A0results[], A1results[], A2results[], and A3results[].
//  Test by applying voltages to channels A0 - A3. Open a watch window in 
//  debugger and view the results. Set Breakpoint1 in the index increment line  
//  to see the array values change sequentially and Breakpoint2 to see the entire
//  array of conversion results in A0results[], A1results[], A2results[], and 
//  A3results[]for the specified Num_of_Results.
//
//  Note that a sequence has no restrictions on which channels are converted.
//  For example, a valid sequence could be A0, A3, A2, A4, A2, A1, A0, and A7.
//  See the MSP430x1xx User's Guide for instructions on using the ADC12.
//
//                 MSP430F249
//            -----------------
//           |                 |
//   Vin0 -->|P6.0/A0          |
//   Vin1 -->|P6.1/A1          |
//   Vin2 -->|P6.2/A2          |
//   Vin3 -->|P6.3/A3          |
//           |                 |
//
//  B. Nisarga
//  Texas Instruments Inc.
//  September 2007
//  Built with CCE Version: 3.2.0 and IAR Embedded Workbench Version: 3.42A
//******************************************************************************

#include  <msp430x23x.h>
//why isn't this included in the above?
//#include <msp430/adc12.h>
//for msp430-gcc interrupts
#include <signal.h>

#define   Num_of_Results   8

//#define pde_debugging

void main(void)
{
  WDTCTL = WDTPW+WDTHOLD;                   // Stop watchdog timer
  #ifdef pde_debugging
    //testing: make P6.0, 6.1 GPIO output
    P6SEL = 0xFC;
    P6DIR = 0x03;
    P5SEL |= 0x70; //turn on clock output to verify lpm
    P5DIR |= 0x70;
  #else
    P6SEL = 0x0F;                             // Enable A/D channel inputs
  #endif

  //turn on switch for sensors 0-3
  P4DIR |= 0x78;
  P4OUT |= 0x78; //0111 1000
  //switch on 4-7
  //0000 1111
  P5DIR |= 0x0F; 
  P5OUT |= 0x0F; 

  //sampling time is dependant on the source resistance:
  //t_sample > (R_s + 2kohm)*9.011*40pF + 800 ns
  //t_sample > (R_s + 2000)*9.011*(40e-12)+800e-9
  //this configuration:
  //ADC12CLK ~= 5 mhz
  //SHT0_8 = 256 cycles ~= 50 uS, about matches the scope output 
  //  (~426uS to sample 8 channels)
  //SHT0_15 = 1024 cycles, active period will have least impact this
  //way.
  //  (~1.64 ms to sample 8 channels). MCLK/CPU is at about 7%
  //  duty-cycle during this time.
  ADC12CTL0 = REFON + REF2_5V+ ADC12ON+MSC+SHT0_15;
                                            // Turn on ADC12, extend sampling time
                                            // generate 2.5 v ref
  ADC12CTL1 = SHP+CONSEQ_3;                 // Use sampling timer, repeated sequence
                                            // this is "pulse sample mode"

  #ifdef pde_debugging
      //testing: don't try to read from P6.0 or 6.1
      ADC12MCTL0 = INCH_2 | SREF_1;
      ADC12MCTL0 = INCH_2 | SREF_1;
  #else
      ADC12MCTL0 = INCH_0 | SREF_1;                      // ref+=VRef, channel = A0
      ADC12MCTL1 = INCH_1 | SREF_1;                      // ref+=VRef, channel = A1
  #endif

  ADC12MCTL2 = INCH_2 | SREF_1;                      // ref+=VRef, channel = A2
  ADC12MCTL3 = INCH_3 | SREF_1;                      // ref+=VRef, channel = A3
  ADC12MCTL4 = INCH_4 | SREF_1;                      // ref+=VRef, channel = A4
  ADC12MCTL5 = INCH_5 | SREF_1;                      // ref+=VRef, channel = A5
  ADC12MCTL6 = INCH_6 | SREF_1;                      // ref+=VRef, channel = A6
  ADC12MCTL7 = INCH_7 | EOS | SREF_1;                  // ref+=VRef, channel = A7, end seq.
  ADC12IE = 0x80;                           // Enable ADC12IFG.7

  ADC12CTL0 |= ENC;                         // Enable conversions
  ADC12CTL0 |= ADC12SC;                     // Start convn - software trigger
  _BIS_SR(LPM4_bits + GIE);                 // Enter LPM4, Enable interrupts
}

interrupt(ADC12_VECTOR) ADC12ISR (void)
{
  static unsigned int result;  //read results/clear ifg's
  result = ADC12MEM0;
  result = ADC12MEM1;
  result = ADC12MEM2;
  result = ADC12MEM3;
  result = ADC12MEM4;
  result = ADC12MEM5;
  result = ADC12MEM6;
  result = ADC12MEM7;
  #ifdef pde_debugging
    //toggle P6.0 on every completion, set P6.1 if measured > 2048 on
    // last channel
    P6OUT = (P6OUT ^(0x01));
    P6OUT = (P6OUT & ~(0x02)) | ((result > 2048)? 0x02 : 0);
  #endif
}
