
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
 * Removed TimerB modules unavailable for msp430f235 
 *
 * @author Cory Sharp <cssharp@eecs.berkeley.edu>
 * @author Doug Carlson <carlson@cs.jhu.edu>
 */

configuration Msp430TimerC
{
  provides interface Msp430Timer as TimerA;
  provides interface Msp430TimerControl as ControlA0;
  provides interface Msp430TimerControl as ControlA1;
  provides interface Msp430TimerControl as ControlA2;
  provides interface Msp430Compare as CompareA0;
  provides interface Msp430Compare as CompareA1;
  provides interface Msp430Compare as CompareA2;
  provides interface Msp430Capture as CaptureA0;
  provides interface Msp430Capture as CaptureA1;
  provides interface Msp430Capture as CaptureA2;

  provides interface Msp430Timer as TimerB;
  provides interface Msp430TimerControl as ControlB0;
  provides interface Msp430TimerControl as ControlB1;
  provides interface Msp430TimerControl as ControlB2;
  provides interface Msp430Compare as CompareB0;
  provides interface Msp430Compare as CompareB1;
  provides interface Msp430Compare as CompareB2;
  provides interface Msp430Capture as CaptureB0;
  provides interface Msp430Capture as CaptureB1;
  provides interface Msp430Capture as CaptureB2;
}
implementation
{
  components new Msp430TimerP( TAIV_, TAR_, TACTL_, TAIFG, TACLR, TAIE,
               TASSEL0, TASSEL1, FALSE ) as Msp430TimerA
           , new Msp430TimerP( TBIV_, TBR_, TBCTL_, TBIFG, TBCLR, TBIE,
               TBSSEL0, TBSSEL1, TRUE ) as Msp430TimerB
           , new Msp430TimerCapComP( TACCTL0_, TACCR0_ ) as Msp430TimerA0
           , new Msp430TimerCapComP( TACCTL1_, TACCR1_ ) as Msp430TimerA1
           , new Msp430TimerCapComP( TACCTL2_, TACCR2_ ) as Msp430TimerA2
           , new Msp430TimerCapComP( TBCCTL0_, TBCCR0_ ) as Msp430TimerB0
           , new Msp430TimerCapComP( TBCCTL1_, TBCCR1_ ) as Msp430TimerB1
           , new Msp430TimerCapComP( TBCCTL2_, TBCCR2_ ) as Msp430TimerB2
          , Msp430TimerCommonP as Common
           ;

  // Timer A
  TimerA = Msp430TimerA.Timer;
  Msp430TimerA.Overflow -> Msp430TimerA.Event[5];
  Msp430TimerA.VectorTimerX0 -> Common.VectorTimerA0;
  Msp430TimerA.VectorTimerX1 -> Common.VectorTimerA1;

  // Timer A0
  ControlA0 = Msp430TimerA0.Control;
  CompareA0 = Msp430TimerA0.Compare;
  CaptureA0 = Msp430TimerA0.Capture;
  Msp430TimerA0.Timer -> Msp430TimerA.Timer;
  Msp430TimerA0.Event -> Msp430TimerA.Event[0];

  // Timer A1
  ControlA1 = Msp430TimerA1.Control;
  CompareA1 = Msp430TimerA1.Compare;
  CaptureA1 = Msp430TimerA1.Capture;
  Msp430TimerA1.Timer -> Msp430TimerA.Timer;
  Msp430TimerA1.Event -> Msp430TimerA.Event[1];

  // Timer A2
  ControlA2 = Msp430TimerA2.Control;
  CompareA2 = Msp430TimerA2.Compare;
  CaptureA2 = Msp430TimerA2.Capture;
  Msp430TimerA2.Timer -> Msp430TimerA.Timer;
  Msp430TimerA2.Event -> Msp430TimerA.Event[2];

  // Timer B
  TimerB = Msp430TimerB.Timer;
  Msp430TimerB.Overflow -> Msp430TimerB.Event[7];
  Msp430TimerB.VectorTimerX0 -> Common.VectorTimerB0;
  Msp430TimerB.VectorTimerX1 -> Common.VectorTimerB1;

  // Timer B0
  ControlB0 = Msp430TimerB0.Control;
  CompareB0 = Msp430TimerB0.Compare;
  CaptureB0 = Msp430TimerB0.Capture;
  Msp430TimerB0.Timer -> Msp430TimerB.Timer;
  Msp430TimerB0.Event -> Msp430TimerB.Event[0];

  // Timer B1
  ControlB1 = Msp430TimerB1.Control;
  CompareB1 = Msp430TimerB1.Compare;
  CaptureB1 = Msp430TimerB1.Capture;
  Msp430TimerB1.Timer -> Msp430TimerB.Timer;
  Msp430TimerB1.Event -> Msp430TimerB.Event[1];

  // Timer B2
  ControlB2 = Msp430TimerB2.Control;
  CompareB2 = Msp430TimerB2.Compare;
  CaptureB2 = Msp430TimerB2.Capture;
  Msp430TimerB2.Timer -> Msp430TimerB.Timer;
  Msp430TimerB2.Event -> Msp430TimerB.Event[2];
}

