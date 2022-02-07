#include "main.h"
// Other includes .....
#include "LiquidCrystal.h"

GPIO D4(GPIOA, 4);
GPIO D5(GPIOA, 5);
GPIO D6(GPIOA, 6);
GPIO D7(GPIOA, 7);
GPIO EN(GPIOB, 0);
GPIO RS(GPIOB, 10);
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup()
{

  //Your setup code here .....

  //LCD setup
  lcd.begin(16, 2);
  lcd.clear();

  //print stuff
  lcd.print("Hello world!!!");
  lcd.setCursor(0,1);
  lcd.blink();
  lcd.print(1234567);
  HAL_Delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Hello, World!!");
  lcd.setCursor(0, 1);
  lcd.print("16x2 LCD Screen Scroooooooliiing!! ");
  HAL_Delay(1000); //Wait a second
}

void loop()
{
  while (1)
  {
    //shift diplay to the left with 16 chars
    for (int l = 0; l < 16; l++)
    {
      lcd.scrollDisplayLeft();
      HAL_Delay(90); //Slight delay for animation
    }
    HAL_Delay(3000);
    //shift diplay to the left with 16 chars
    for (int l = 0; l < 16; l++)
    {
      lcd.scrollDisplayLeft();
      HAL_Delay(90); //Slight delay for animation
    }
    //shift diplay to the left with 8 chars (should go back to home position)
    for (int l = 0; l < 8; l++)
    {
      lcd.scrollDisplayLeft();
      HAL_Delay(90); //Slight delay for animation
    }
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);//Toggle an led
    HAL_Delay(3000);
  }
}
