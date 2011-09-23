//$Id: Msp430Timer32khzMapC.nc,v 1.4 2006/12/12 18:23:11 vlahan Exp $

/* "Copyright (c) 2000-2003 The Regents of the University of California.
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement
 * is hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the author appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY
 * OF CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 */

/**
 * Msp430Timer32khzMapC presents as paramaterized interfaces all of the 32khz
 * hardware timers on the MSP430 that are available for compile time allocation
 * by "new Alarm32khz16C()", "new AlarmMilli32C()", and so on.
 *
 * Platforms based on the MSP430 are encouraged to copy in and override this
 * file, presenting only the hardware timers that are available for allocation
 * on that platform.
 *
 * @author Cory Sharp <cssharp@eecs.berkeley.edu>
 */

/* Currently, all MSP430XV2 architectures support T0A5, so we'll use
 * that for the 32KHz timer suite.  If you clone this to a platform
 * area, remember to also clone Msp430Counter32khzC if you change to a
 * different timer. */

configuration Msp430Timer32khzMapC
{
  provides interface Msp430Timer[ uint8_t id ];
  provides interface Msp430TimerControl[ uint8_t id ];
  provides interface Msp430Compare[ uint8_t id ];
}
implementation
{
  components Msp430TimerC;

  Msp430Timer[0] = Msp430TimerC.Timer0_A;
  Msp430TimerControl[0] = Msp430TimerC.Control0_A0;
  Msp430Compare[0] = Msp430TimerC.Compare0_A0;

  Msp430Timer[1] = Msp430TimerC.Timer0_A;
  Msp430TimerControl[1] = Msp430TimerC.Control0_A1;
  Msp430Compare[1] = Msp430TimerC.Compare0_A1;

  Msp430Timer[2] = Msp430TimerC.Timer0_A;
  Msp430TimerControl[2] = Msp430TimerC.Control0_A2;
  Msp430Compare[2] = Msp430TimerC.Compare0_A2;

  Msp430Timer[3] = Msp430TimerC.Timer0_A;
  Msp430TimerControl[3] = Msp430TimerC.Control0_A3;
  Msp430Compare[3] = Msp430TimerC.Compare0_A3;

  Msp430Timer[4] = Msp430TimerC.Timer0_A;
  Msp430TimerControl[4] = Msp430TimerC.Control0_A4;
  Msp430Compare[4] = Msp430TimerC.Compare0_A4;

}

