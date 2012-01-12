Test firmware for "toast" board. It's expected that a 20 Kohm load is
connected from each SENSORx PWR to GND. 

- LPM3_internal.c : set up pins to minimize current consumption, put MCU into
  LPM3 (ACLK remains on, sourced from internal VLOCLK). Datasheet: < 1
  uA.
- LPM3_external.c : set up pins to minimize current consumption, put
  MCU into LPM3 (32khz external crystal remains on). Datasheet: < 1.4
  uA.
- LPM4.c : set up pins to minimize current consumption, put MCU into
  LPM4 (all clocks off). Datasheet: < 0.5 uA.
- ADC.c : Close analog sensor power switches, perform repeated ADC
  samples using internal reference voltage. Range should vary from
  2.9005 mA to 3.35 mA. Averaged over time, it should be around 2.927
  mA.
  - ADC12: < 1.7 mA (I_ADC12 + I_REF+) from datasheet
  - Sensors: 1.2 mA (20 Kohm load on each sensor channel: @3.0 V,
    0.00015 amps per sensor = 0.0012 amps for 8 channels (1.2 mA))
  - Active mode @ 1 mhz: <= 450 uA
  - LPM4 : < 0.5 uA
  - On scope, looks like about 100uS in active mode / 1.64 ms sample
    cycle (6% duty cycle)
  - active:
    - 0.450 mA CPU
    - 1.7 mA ADC12
    - 1.2 mA sensors
    - 3.350 mA total (switch leakage is o(nA))
  - sleep:
    - 0.0005 mA CPU
    - 1.7 mA ADC12
    - 1.2 mA sensors
    - 2.9005 mA total
  - (0.94*2.9005) + (0.06*3.35) = 2.927 mA average
- aclk_only.c : source ACLK from 32khz XT1 crystal, output on P5.6
  (TP28)
