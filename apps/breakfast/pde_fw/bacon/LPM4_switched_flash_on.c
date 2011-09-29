//******************************************************************************
//   CC430x513x Demo - Enters LPM3 (ACLK = LFXT1)
//
//   Description: Configure ACLK = LFXT1 and enters LPM3. Measure current.
//   Note: SVS(H,L) & SVM(H,L) are disabled
//   ACLK = LFXT1 = 32kHz, MCLK = SMCLK = default DCO
//
//                 CC430x513x
//             -----------------
//        /|\ |              XIN|-
//         |  |                 | 32kHz
//         ---|RST          XOUT|-
//            |                 |
//
//   M. Morales
//   Texas Instruments Inc.
//   April 2009
//   Built with CCE Version: 3.2.2 and IAR Embedded Workbench Version: 4.11B
//******************************************************************************

#include  "cc430x513x.h"

void main(void)
{  
  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT

  P5SEL |= BIT0 + BIT1;                     // Select XT1
  UCSCTL6 |= XCAP_3;                        // Internal load cap

  // Loop until XT1,XT2 & DCO stabilizes
  do
  {
    UCSCTL7 &= ~(XT1LFOFFG + DCOFFG);
                                            // Clear LFXT1,DCO fault flags
    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  }while (SFRIFG1 & OFIFG);                   // Test oscillator fault flag

  UCSCTL6 &= ~(XT1DRIVE_3);                 // Xtal is now stable, reduce drive
                                            // strength
  //7 active low
  P1OUT = 0x80; 
  P1DIR = 0xFF; 
  //P1.7: flash CS# out vcc
  
//  // map MCLK/ACLK out to P1.5/P1.6 (to check LPM state)
  PMAPPWD = 0x2D52;
  P1MAP5 = PM_MCLK;
  P1MAP6 = PM_ACLK;
  PMAPPWD = 0;
  P1SEL = 0x20;

  //inputs on 0,2,5
  // 1101 1010
  P2OUT = 0x00; 
  P2DIR = 0xDA; 
  //P2.0: VBAT sense (input? out to gnd?)
  //P2.2: light sense (input? out to gnd?)
  //P2.5: thermistor sense (input? out to gnd?)
  //P2.6/2.7: I2C (out to gnd)

  //0,1,2,3 active low
  P3OUT = 0x8F; 
  P3DIR = 0xFF;
  //P3.0/1/2: LEDs out to vcc
  //P3.3: photo shutdown (out vcc)
  //P3.7: vcc enable (gnd out)

  //just the external crystal
  P5OUT = 0x00;
  P5DIR = 0x03;
  
  //PJ.1/J.2: gnd out
  PJOUT = 0x00;
  PJDIR = 0xFF;

  // Turn off SVSH, SVSM
  PMMCTL0_H = 0xA5;
  SVSMHCTL = 0; 
  SVSMLCTL = 0; 
  PMMCTL0_H = 0x00; 
  
//  while (1){
//    P3OUT ^= 0x01;
//  }
  __bis_SR_register(LPM4_bits);             // Enter LPM3
  __no_operation();                         // For debugger
}
