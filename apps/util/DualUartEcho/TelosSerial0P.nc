module TelosSerial0P {
  provides interface Msp430UartConfigure;
}
implementation {
  
  msp430_uart_union_config_t msp430_uart_telos_config = { {ubr: UBR_1MHZ_115200, umctl: UMCTL_1MHZ_115200, ssel: 0x02, pena: 0, pev: 0, spb: 0, clen: 1, listen: 0, mm: 0, ckpl: 0, urxse: 0, urxeie: 1, urxwie: 0, utxe : 1, urxe : 1} };

  async command msp430_uart_union_config_t* Msp430UartConfigure.getConfig() {
    return &msp430_uart_telos_config;
  }
  
}
