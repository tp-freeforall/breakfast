;*******************************************************************************
;   MSP430x24x Demo - USCI_A0, SPI Interface to HC165/164 Shift Registers
;
;   Description: Demonstrate USCI_A0 in two-way SPI mode. Data are read from
;   an HC165, and same data written back to the HC164.
;   ACLK = n/a  MCLK = SMCLK = DCOCLK = ~1.2MHz, BRCLK = SMCLK/2
;
;                            MSP430x24x
;                       --------------------
;                   /|\|                 XIN|-
;                    | |                    |     ^      HC164
;          HC165     --|RST             XOUT|-    |  -------------
;        ----------    |                    |     |-|/CLR,B       |  8
;    8  |      /LD|<---|P3.6   UCA0SIMO/P3.4|------>|A          Qx|--\->
;   -\->|A-H   CLK|<---|P3.0/UCA0CLK -- P3.0|------>|CLK          |
;     |-|INH    QH|--->|P3.5/UCA0SOMI       |       |             |
;     |-|SER      |    |                    |       |             |
;     - |         |    |                    |       |             |
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
StopWDT     mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; Stop watchdog timer
SetupP3     bis.b   #031h,&P3SEL            ; P3.0,4,5 USCI_A0 option select
            bis.b   #040h,&P3DIR            ; P3.6 output direction
SetupSPI    bis.b   #UCCKPH+UCMSB+UCMST+UCSYNC,&UCA0CTL0 ; 3-pin, 8-bit SPI mast
            bis.b   #UCSSEL_2,&UCA0CTL1     ; SMCLK
            bis.b   #02h,&UCA0BR0
            clr.b   &UCA0BR1                ;
            clr.b   &UCA0MCTL
            bic.b   #UCSWRST,&UCA0CTL1      ; **Initialize USCI state machine**
                                            ;
Mainloop    call    #RXTX_HC16x             ; Exchange data
Delay       push.w  #0                      ; Software delay
D1          dec.w   0(SP)                   ;
            jnz     D1                      ;
            incd.w  SP                      ;
            jmp     Mainloop                ; Repeat
                                            ;
;-------------------------------------------------------------------------------
RXTX_HC16x;   HC165--> UCA0RXBUF  UCA0TXBUF --> HC164
;-------------------------------------------------------------------------------
TX0         bit.b   #UCA0TXIFG,&IFG2        ; USCI_A0 TX buffer ready?
            jz      TX0                     ; Jump --> TX buffer not ready
            bic.b   #040h,&P3OUT            ; Latch data into 'HC165
            bis.b   #040h,&P3OUT            ;
            mov.b   &UCA0RXBUF,&UCA0TXBUF   ; Previous data to TX, RX next
            ret                             ; Return from subroutine
                                            ;
;-------------------------------------------------------------------------------
;			Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect	".reset"            ; POR, ext. Reset
            .short  RESET      
            .end
