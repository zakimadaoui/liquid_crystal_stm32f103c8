# LiquidCrystal Library for STM32F1

This is a port of the [Arduino LiquidCrystal](https://github.com/arduino-libraries/LiquidCrystal) Library to the STM32F103C8. It allows you to control liquid crystal displays (LCDs) based on the Hitachi HD44780 (or a compatible) chipset, which is found on most text-based LCDs.

**Note**: this port supports only the STM32F103C8 MCU as it controls GPIOs from registers directly. if you want to use it with a different micro-controller, then you just need to re-implement functions like `micros(), digitalWrite() and pinMode()` in **LiquidCristal.cpp** and **micros.c**.


