/*
* Damian Podraza 2023
*/

#if defined(ARDUINO_DISCOF407)

#include "pins_arduino.h"

// Pin number
const PinName digitalPin[] = {
  //P1 connector Right side
  PC_0,  //D0/A14
  PC_2,  //D1/A0
  PA_0,  //D2/A15
  PA_2,  //D3/A8
  PA_4,  //D4/A10
  PA_6,  //D5/A12
  PC_4,  //D6/A1
  PB_0,  //D7/A2
  PB_2,  //D8
  PE_8,  //D9
  PE_10, //D10
  PE_12, //D11
  PE_14, //D12
  PB_10, //D13
  PB_12, //D14
  PB_14, //D15
  PD_8,  //D16
  PD_10, //D17
  PD_12, //D18
  PD_14, //D19
  //P2 connector Left side
  PH_0,  //D20
  PC_14, //D21
  PE_6,  //D22
  PE_4,  //D23
  PE_2,  //D24
  PE_0,  //D25
  PB_8,  //D26
  PB_6,  //D27
  PB_4,  //D28
  PD_7,  //D29
  PD_5,  //D30
  PD_3,  //D31
  PD_1,  //D32
  PC_12, //D33
  PC_10, //D34
  PA_10, //D35
  PA_8,  //D36
  PC_8,  //D37
  PC_6,  //D38
  //P1 Connector Left Side
  PC_1,  //D39/A3
  PC_3,  //D40/A4
  PA_1,  //D41/A5
  PA_3,  //D42/A9
  PA_5,  //D43/A11
  PA_7,  //D44/A13
  PC_5,  //D45/A6
  PB_1,  //D46/A7
  PE_7,  //D47
  PE_9,  //D48
  PE_11, //D49
  PE_13, //D50
  PE_15, //D51
  PB_11, //D52
  PB_13, //D53
  PB_15, //D54
  PD_9,  //D55
  PD_11, //D56
  PD_13, //D57
  PD_15, //D58
  //P2 connector Right side
  PH_1,  //D59
  PC_15, //D60
  PC_13, //D61
  PE_5,  //D62
  PE_3,  //D63
  PE_1,  //D64
  PB_9,  //D65
  PB_7,  //D66
  PB_5,  //D67
  PB_3,  //D68
  PD_6,  //D69
  PD_4,  //D70
  PD_2,  //D71
  PD_0,  //D72
  PC_11, //D73
  PA_15, //D74
  PA_13, //D75
  PA_9,  //D76
  PC_9,  //D77
  PC_7   //D78
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  1,  //A0
  6,  //A1
  7,  //A2
  39, //A3
  40, //A4
  41, //A5
  45, //A6
  46, //A7
  3,  //A8
  42, //A9
  4,  //A10
  43, //A11
  5,  //A12
  44, //A13
  0,  //A14
  2   //A15
};

#ifdef __cplusplus
extern "C" {
#endif
  WEAK void SystemClock_Config(void) {
  }
#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_DISCOF407 */
