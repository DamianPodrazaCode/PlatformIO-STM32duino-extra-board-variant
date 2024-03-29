/*
* Damian Podraza 2023
*/

#pragma once

 //P1 connector Right side
#define PC0                     PIN_A14
#define PC2                     PIN_A0
#define PA0                     PIN_A15
#define PA2                     PIN_A8
#define PA4                     PIN_A10
#define PA6                     PIN_A12
#define PC4                     PIN_A1
#define PB0                     PIN_A2
#define PB2                     8
#define PE8                     9
#define PE10                    10
#define PE12                    11
#define PE14                    12
#define PB10                    13
#define PB12                    14
#define PB14                    15
#define PD8                     16
#define PD10                    17
#define PD12                    18
#define PD14                    19
//P2 connector Left side
#define PH0                     20
#define PC14                    21
#define PE6                     22
#define PE4                     23
#define PE2                     24
#define PE0                     25
#define PB8                     26
#define PB6                     27
#define PB4                     28
#define PD7                     29
#define PD5                     30
#define PD3                     31
#define PD1                     32
#define PC12                    33
#define PC10                    34
#define PA10                    35
#define PA8                     36
#define PC8                     37
#define PC6                     38
//P1 Connector Left Side
#define PC1                     PIN_A3
#define PC3                     PIN_A4
#define PA1                     PIN_A5
#define PA3                     PIN_A9
#define PA5                     PIN_A11
#define PA7                     PIN_A13
#define PC5                     PIN_A6
#define PB1                     PIN_A7
#define PE7                     47
#define PE9                     48
#define PE11                    49
#define PE13                    50
#define PE15                    51
#define PB11                    52
#define PB13                    53
#define PB15                    54
#define PD9                     55
#define PD11                    56
#define PD13                    57
#define PD15                    58
//P2 connector Right side
#define PH1                     59
#define PC15                    60
#define PC13                    61
#define PE5                     62
#define PE3                     63
#define PE1                     64
#define PB9                     65
#define PB7                     66
#define PB5                     67
#define PB3                     68
#define PD6                     69
#define PD4                     70
#define PD2                     71
#define PD0                     72
#define PC11                    73
#define PA15                    74
#define PA13                    75
#define PA9                     76
#define PC9                     77
#define PC7                     78

// Alternate pins number
#define PA0_ALT1                (PA0  | ALT1)
#define PA1_ALT1                (PA1  | ALT1)
#define PA2_ALT1                (PA2  | ALT1)
#define PA2_ALT2                (PA2  | ALT2)
#define PA3_ALT1                (PA3  | ALT1)
#define PA3_ALT2                (PA3  | ALT2)
#define PA4_ALT1                (PA4  | ALT1)
#define PA7_ALT1                (PA7  | ALT1)
#define PA15_ALT1               (PA15 | ALT1)
#define PB0_ALT1                (PB0  | ALT1)
#define PB1_ALT1                (PB1  | ALT1)
#define PB3_ALT1                (PB3  | ALT1)
#define PB4_ALT1                (PB4  | ALT1)
#define PB5_ALT1                (PB5  | ALT1)
#define PB8_ALT1                (PB8  | ALT1)
#define PB9_ALT1                (PB9  | ALT1)

#define NUM_DIGITAL_PINS        79
#define NUM_ANALOG_INPUTS       16

// On-board LED pin number
#define LED_GREEN               PD12
#define LED_BLUE                PD15
#define LED_RED                 PD14
#define LED_ORANGE              PD13
#ifndef LED_BUILTIN
#define LED_BUILTIN           LED_GREEN
#endif

// On-board user button
#ifndef USER_BTN
#define USER_BTN              PA0
#endif

// Timer Definitions
// Use TIM10/TIM11 when possible as servo and tone don't need GPIO output pin
#ifndef TIMER_TONE
#define TIMER_TONE            TIM10
#endif
#ifndef TIMER_SERVO
#define TIMER_SERVO           TIM11
#endif

// UART Definitions
#ifndef SERIAL_UART_INSTANCE
#define SERIAL_UART_INSTANCE  2
#endif

// Default pin used for generic 'Serial' instance
// Mandatory for Firmata
#ifndef PIN_SERIAL_RX
#define PIN_SERIAL_RX         PA3
#endif
#ifndef PIN_SERIAL_TX
#define PIN_SERIAL_TX         PA2
#endif

// Extra HAL modules
//#if !defined(HAL_SD_MODULE_DISABLED)
//#define HAL_SD_MODULE_ENABLED
//#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
 // These serial port names are intended to allow libraries and architecture-neutral
 // sketches to automatically default to the correct port name for a particular type
 // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
 // the first hardware serial port whose RX/TX pins are not dedicated to another use.
 //
 // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
 //
 // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
 //
 // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
 //
 // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
 //
 // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
 //                            pins are NOT connected to anything by default.
#ifndef SERIAL_PORT_MONITOR
#define SERIAL_PORT_MONITOR   Serial
#endif
#ifndef SERIAL_PORT_HARDWARE
#define SERIAL_PORT_HARDWARE  Serial
#endif
#endif
