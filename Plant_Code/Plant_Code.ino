//Sample using LiquidCrystal library
#include <LiquidCrystal.h>
 
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
 int desired_moisture = 0;
 int current_moisture1 = 0;
// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5
int current_moisture = 0;
// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 if (adc_key_in < 50)   return btnRIGHT; 
 if (adc_key_in < 195)  return btnUP;
 if (adc_key_in < 380)  return btnDOWN;
 if (adc_key_in < 555)  return btnLEFT;
 if (adc_key_in < 790)  return btnSELECT;  
 return btnNONE;  // when all others fail, return this...
}
 
void setup()
{
 pinMode(8, OUTPUT);
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 
}
  
void loop()
{
  current_moisture1 = analogRead(A5); 
  current_moisture = current_moisture1 / 10;
if (current_moisture < desired_moisture) {
       tone(A4, 1000, 500);  //Play a buzzer tone for half a second
  }





  
 lcd.setCursor(0,0);            // move cursor to second line "1" and 9 spaces over
      // display seconds elapsed since power-up
 lcd.print("Target: ");
 lcd.print(desired_moisture);
 
 lcd.setCursor(0,1);  
 lcd.print("Moisture: ");
 lcd.print(current_moisture);
 lcd_key = read_LCD_buttons();  // read the buttons
 
 switch (lcd_key)               // depending on which button was pushed, we perform an action
 {
   case btnRIGHT:
     {
    
     break;
     }
   case btnLEFT:
     {
     
     break;
     }
   case btnUP:
     {
      
     
     desired_moisture++;
     delay(200);
     lcd.clear();
     break;
     }
   case btnDOWN:
     {
     
     
     desired_moisture--;
     delay(200);
     lcd.clear();
     break;
     }
   case btnSELECT:
     {
     lcd.clear();
     break;
     }
     case btnNONE:
     {
     
     break;
     }
 }
 
}

