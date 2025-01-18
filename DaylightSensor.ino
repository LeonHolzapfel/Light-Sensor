// C++ code
//
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);
// min and max Value for the map function
const int sensorMin = 6;
const int sensorMax = 679;

// this will be used to check if the value has changed later
int lightValue = 0;

void setup()
{
  //Set the pins on the Arduino
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);

  //Initiate the LCD and set the title
  lcd_1.begin(16, 2);
  lcd_1.print("Daylight Sensor");
}

void loop()
{
  // get the Sensorvalue and create a map
  int sensorValue = analogRead(A0);
  int daylight = map(sensorValue, sensorMin, sensorMax, 0, 3);

  // set Cursor to display Daytime on second line
  lcd_1.setCursor(0, 1);
  

  // this will check if the value has changed otherwise the same value will be writen over and over
  if (sensorValue != lightValue) {    
    lightValue = sensorValue;
    
    // clear the second line
    lcd_1.print("        ");
    lcd_1.setCursor(0, 1);
    
    // this will display the current Daytime, if it is night or dusk the lamp will be turned on,
    // at daytime the Lamp will stay off
    switch(daylight) {
      case 0:
        lcd_1.print("Night");
        digitalWrite(7, HIGH);
        break;
      case 1:
        lcd_1.print("Dusk");
        digitalWrite(7, HIGH);
        break;
      case 2:
        lcd_1.print("Day");
        digitalWrite(7, LOW);
        break;
    }
  }
}