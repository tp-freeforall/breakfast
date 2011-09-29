;******************************************************************************
;   MSP430x249 Demo - Write a byte to Port 1
;
;   Description: Writes a byte(FFh) to Port 1 and stays in LPM4
;   ACLK = 32.768kHz, MCLK = SMCLK = default DCO
;
;                MSP430x249
;             -----------------
;         /|\|                 |
;          | |                 |
;          --|RST              |
;            |                 |
;            |                 |
;            |                 |
;
;  JL Bile
;  Texas Instruments Inc.
;  May 2008
;  Built Code Composer Essentials: v3 FET
;*******************************************************************************
 .cdecls C,LIST, "msp430x24x.h"
;-------------------------------------------------------------------------------
			.text	;Program Start
;-------------------------------------------------------------------------------
RESET       mov.w   #0500h,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop WDT
SetupP1     bis.b   #0FFh,&P1DIR            ; P1.x output
            bis.b   #0FFh,&P1OUT            ; Set all P1 pins HI
                                            ;
Mainloop    bis.w   #LPM4,SR                ; LPM4
            nop                             ; Required only for debugger
                                            ;
;------------------------------------------------------------------------------
;			Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect	".reset"            ; POR, ext. Reset
            .short    RESET
            .end
            