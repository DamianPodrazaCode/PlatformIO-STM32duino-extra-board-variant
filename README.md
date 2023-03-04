# PlatformIO-STM32duino-extra-board-variant
## Tworzenie własnych variantów płytek w STM32duino dla PlatformIO:

### 1. Są dwa miejsca do których trzeba stworzyć komplet plików aby pojawiła się nowa opcja płytki:
#
>**Pierwsze: "c:\Users\\[userName]\\.platformio\platforms\ststm32\boards\"**

Tutaj są pliki z opisem konfiguracji "[nazwa płytki].json" (np. "discoF429.json"), 
co ciekawe ta nazwa będzie później rozszerzeniem nazwy kolejnych plików konfiguracyjnych, oraz stałej w frameworku -  "ARDUINO_[NAZWA PŁYTKI]", np: "ARDUINO_DISCOF429", z tą zmianą że jak przystało na stałą w "C" jest pisana drukowanymi literami.

>**Drugie miejsce: "c:\Users\[userName]\.platformio\packages\framework-arduinoststm32\variants\"**

Tutaj się tworzy folder z wariantem (np.: folder "extraVariants/discoF429"),w których jest kilka plików:
* "ldscript.ld" - pliki "*.ld" można znaleźć w "c:\Users\\[userName]\\.platformio\packages\tool-ldscripts-ststm32\", po wybraniu odpowiedniego do procka pliku należy mu zmienić nazwę na "ldscript.ld".

Aby mieć pliki *ld czyli "tool-ldscripts-ststm32": 

* Open PlatformIO Core CLI
* Copy the following pio pkg install command and paste into the CLI shell, press Enter:
```
pio pkg install -g --tool "platformio/tool-ldscripts-ststm32@^0.2.0"
```
Reszta plików jest kopiowana z wersji GENERIC:
* "PeripheralPins_[nazwa płytki].c" (np.: PeripheralPins_discoF429.c)
* "PinNamesVar.h"
* "variant_[nazwa płytki].cpp" (np.: variant_discoF429.cpp)
* "variant_[nazwa płytki].h" (np.: variant_discoF429.h)

#

### 2. Budowa pliku "[nazwa płytki].json" (np. "discoF429.json").
#

```java
{
  "build": {
    "core": "stm32",  // tutaj jest rdzeń dla arduino żeby biblioteki wiedziały 
    "cpu": "cortex-m4", //rodzaj procka
    "extra_flags": "-DSTM32F4 -DSTM32F429xx", // flagi kompilatora, można podejrzeć w innych plikach json, 
    "mcu": "stm32f429zit6", // dokładna nazwa cpu 
    "product_line": "STM32F429xx", //(boards.txt sekcja GENERIC)
    "variant": "myVariants/discoF429", //folder z plikami do wariantu  
    "framework_extra_flags": { //flagi dla wyszczególnionych frameworków
      "arduino": "-DCUSTOM_PERIPHERAL_PINS" //flaga do używania specjalnych nazw wariantów w katalogu wariantów
    }
  },
  "debug": {
    "openocd_target": "stm32f4x", // nazwa pliku ".cfg" z c:\Users\[userName]\.platformio\packages\tool-openocd\scripts\target\
    "svd_path": "STM32F429x.svd" //pliki w c:\Users\[userName]\.platformio\platforms\ststm32\misc\svd\
  },
  "frameworks": [
    "arduino"
  ],
  "name": "myST Discovery STM32F429ZIT", //nawa po której jest wyszukiwana płytka przy tworzeniu projektu
  "upload": {
    "maximum_size": 2097152,  // wielkość flash pobrać z  boards.txt sekcja GENERIC
    "maximum_ram_size": 196608, // wielkość ram pobrać z  boards.txt sekcja GENERIC, moża być niezgodna z opisem w DS cpu
    "protocol": "stlink", 
    "protocols": [
      "stlink"
    ]
  },
  "url": "https://www.st.com", 
  "vendor": "ST"
}
```

Plik "boards.txt" jest w "c:\Users\\[userName]\\.platformio\packages\framework-arduinoststm32\". 

Plik "*.json" nie może zawierać komentarzy, tu są tylko w celu objaśnień.
#
### 3. Uzupełnienie katalogu z wariantem, przykładem będzie STM32F429ZIT6.

#
Odszukujemy odpowiednią rodzinę wariantu procka w folderze 
"c:\Users\\[userName]\\.platformio\packages\framework-arduinoststm32\variants\", w tym przypadku to "STM32F4xx", wchodzimy do folderu i widzimy wiele różnych opcji, wybieramy odpowiedzi katalog, katalogi te są trochę zakodowane:), na przykładzie procka F429ZIT wyszukujemy folder "F427Z(G-I)T_F429ZET_F429Z(G-I)(T-Y)_F437Z(G-I)T_F439Z(G-I)(T-Y)".
#

Kopiujemy do utworzonego wcześniej folderu z naszym wariantem, czyli "c:\Users\\[userName]\\.platformio\packages\framework-arduinoststm32\variants\myVariants\discoF429\" pliki:
- PeripheralPins.c
- PinNamesVar.h
- variant_generic.cpp
- variant_generic.h
- oraz odpowiednio przygotowany wcześniej plik "ldscript.ld".
Zmieniamy nazwy plików na:
- PeripheralPins.c na  PeripheralPins_discoF429 .c (końcówka "_discoF429" musi być zgodna z wcześniej utworzonym plikiem "discoF429.json")
- variant_generic.cpp na "variant_discoF429.cpp"
- variant_generic.h na "variant_ discoF429.cpp"
# 

### 4. Poprawki w  "PeripheralPins_discoF429 .c"

#
Zamienić  linie na początku pliku,
```c
#if !defined(CUSTOM_PERIPHERAL_PINS)
```
 na
```c
#if defined(ARDUINO_DISCOF429)
```
skąd się wzięła definicja  **ARDUINO_DISCOF429** pisałem wcześniej.

#
 ### 5. Poprawki w pliku "variant_discoF429.cpp"

 #
 Zamienić całego **#if...** (zwróć uwagę że przeważnie jest wieloliniowy) na 
```c
#if defined(ARDUINO_DISCOF429)
```

#

### 6. Funkcja ustawiająca zegary w STM32.

#
Na końcu pliku ale przed #endif w "variant_discoF429.cpp" , trzeba dodać funkcję:

```c++
#ifdef __cplusplus
extern "C" {
#endif
  WEAK void SystemClock_Config(void) {
	// tutaj funkcja ustawiająca zegary 
    SystemCoreClock = [prędkość w Hz];
    HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq));
  }
#ifdef __cplusplus
}
#endif
```
Jeżeli nie doda się SystemClock_Config() to kompilator się upomni o nią.
Całą tą funkcję można wygenerować za pomocą STMCubeMX, albo wziąć z repozytoriów STMCube z przykładów.

Przykład do discoF429:

```c++
#ifdef __cplusplus
extern "C" {
#endif
 
    // zegar na 180MHz, bez używania USB
    WEAK void SystemClock_Config(void) {
        __HAL_RCC_PWR_CLK_ENABLE();
        __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
        RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
        RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
        RCC_OscInitStruct.HSEState = RCC_HSE_ON;
        RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
        RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
        RCC_OscInitStruct.PLL.PLLM = 4;
        RCC_OscInitStruct.PLL.PLLN = 180;
        RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
        RCC_OscInitStruct.PLL.PLLQ = 4;
        HAL_RCC_OscConfig(&RCC_OscInitStruct);
        HAL_PWREx_EnableOverDrive();
        RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };
        RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
        RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
        RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
        RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
        RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
        HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
        __HAL_RCC_CCMDATARAMEN_CLK_ENABLE(); /* Ensure CCM RAM clock is enabled */
        HAL_RCC_EnableCSS();
        SystemCoreClock = 180000000UL;
        HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq));
    }
#ifdef __cplusplus
}
#endif

```

#

## W repo jest kilka płytek z których ja osobiście korzystam wystarczy je skopiować w odpowiednie miejsca wg. punktu 1.
#

Gotowe płytki:

* Discovery kit for STM32F401 (32F401CDISCOVERY, STM32F401VCT6)
* Discovery kit with STM32F407 (STM32F4DISCOVERY, STM32F407VGT6)
* Discovery kit with STM32F429 (32F429IDISCOVERY, STM32F429ZIT6)
* Discovery kit for STM32F7 Series with STM32F746NG (32F746GDISCOVERY)
* Discovery kit with STM32F769N (32F769IDISCOVERY)
* NUCLEO-F207ZG
* NUCLEO-F411RE
* NUCLEO-F439ZI
* NUCLEO-F746ZG

