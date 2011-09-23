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
 * Configuration for the clocks and timers on an MSP430XV2 system.
 *
 * This component sets MCLK to 2^22Hz (4MHz), SMCLK to 2^2Hz (1MHz),
 * and ACLK to 2^15Hz (32KHz).  Timer A0 uses ACLK and is enabled.  If
 * available, Timer A1 uses SMCLK and is enabled.
 *
 * If your board requires other configurations, implement
 * Msp430XV2ClockInit in your own component and connect to this
 * implementation's events to override each configuration step as
 * necessary.
 *
 * @author Cory Sharp <cssharp@eecs.berkeley.edu>
 * @author Peter A. Bigot <pab@peoplepowerco.com>
 */

configuration Msp430XV2ClockC
{
  provides interface Init;
  provides interface Msp430XV2ClockControl;
  provides interface StdControl as InhibitUcs7WorkaroundControl;
}
implementation
{
  components Msp430XV2ClockP;
  Init = Msp430XV2ClockP;

  /* Must reference Msp430TimerC, since the Msp430XV2ClockInit code
   * will enable interrupts that are only defined if that component is
   * linked in. */
  components Msp430TimerC;

  components Msp430XV2ClockControlP;
  Msp430XV2ClockControl = Msp430XV2ClockControlP;
  InhibitUcs7WorkaroundControl = Msp430XV2ClockControlP.InhibitUcs7WorkaroundControl;
  Msp430XV2ClockP.Msp430XV2ClockControl -> Msp430XV2ClockControlP;

  components McuSleepC;
  McuSleepC.McuPowerOverride -> Msp430XV2ClockControlP;

  /* Work around UCS7 */
  Msp430XV2ClockControlP.McuSleepEvents -> McuSleepC;
}
