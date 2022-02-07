#ifndef LiquidCrystal_h
#define LiquidCrystal_h

#include <stdint.h>
#include "stm32f103xb.h"

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

#define HIGH 1U
#define LOW 0U
#define INPUT 1U
#define OUTPUT 0U


struct GPIO
{
  GPIO(){}
  GPIO(GPIO_TypeDef *gpio_port, uint32_t pin): gpio_port(gpio_port), pin(pin) {}
  GPIO_TypeDef *gpio_port;     /*!< Specifies the Port for the selected pins.
                           This parameter can be a value of @addtogroup Peripheral_declaration*/
  uint32_t      pin;       /*!< Specifies the GPIO pins to be configured.
                           This parameter can be any value of @ref GPIO_pins_define */
};



class LiquidCrystal {
public:
  LiquidCrystal(GPIO& rs, GPIO& enable,
		GPIO& d0, GPIO& d1, GPIO& d2, GPIO& d3,
		GPIO& d4, GPIO& d5, GPIO& d6, GPIO& d7);
  LiquidCrystal(GPIO& rs, GPIO& rw, GPIO& enable,
		GPIO& d0, GPIO& d1, GPIO& d2, GPIO& d3,
		GPIO& d4, GPIO& d5, GPIO& d6, GPIO& d7);
  LiquidCrystal(GPIO& rs, GPIO& rw, GPIO& enable,
		GPIO& d0, GPIO& d1, GPIO& d2, GPIO& d3);
  LiquidCrystal(GPIO& rs, GPIO& enable,
		GPIO& d0, GPIO& d1, GPIO& d2, GPIO& d3);

  void init(uint8_t fourbitmode, GPIO& rs, GPIO& rw, GPIO& enable,
	    GPIO& d0, GPIO& d1, GPIO& d2, GPIO& d3,
	    GPIO& d4, GPIO& d5, GPIO& d6, GPIO& d7);
    
  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

  void clear();
  void home();

  void noDisplay();
  void display();
  void noBlink();
  void blink();
  void noCursor();
  void cursor();
  void scrollDisplayLeft();
  void scrollDisplayRight();
  void leftToRight();
  void rightToLeft();
  void autoscroll();
  void noAutoscroll();

  void setRowOffsets(int row1, int row2, int row3, int row4);
  void createChar(uint8_t, uint8_t[]);
  void setCursor(uint8_t, uint8_t); 
  void write(uint8_t value);
  void print(const char string[]);
  void print(int nbr);
  void command(uint8_t);
  
private:
  void send(uint8_t, uint8_t);
  void write4bits(uint8_t);
  void write8bits(uint8_t);
  void pulseEnable();
  void digitalWrite(GPIO gpio, uint8_t data);
  void pinMode(GPIO gpio, uint8_t mode);

  GPIO _rs_pin; // LOW: command.  HIGH: character.
  GPIO _rw_pin; // LOW: write to LCD.  HIGH: read from LCD.
  GPIO _enable_pin; // activated by a HIGH pulse.
  GPIO _data_pins[8];

  uint8_t _displayfunction;
  uint8_t _displaycontrol;
  uint8_t _displaymode;

  uint8_t _initialized;

  uint8_t _numlines;
  uint8_t _row_offsets[4];
};

#endif
