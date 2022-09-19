#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int contrast_PIN = 12; //original pin no: 9
int contrast= 20; 

int background_light_PIN = 8;//original pin no: 8 , deffo not 14
int background_light = 100;   
int analog_value;

void setup() {
  Serial.begin(9600);

  pinMode(background_light_PIN, OUTPUT);
  pinMode(contrast_PIN, OUTPUT);


  analogWrite(background_light_PIN, background_light);
  analogWrite(contrast_PIN, contrast);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);  
}

void loop() {
  analog_value = analogRead(A0) / 100;
  
  // Sender der Information an den LCD
  lcd.setCursor(0, 0);
  lcd.print("No way!");

  lcd.setCursor(0, 1);
  lcd.print(analog_value);
  lcd.print('-');
  lcd.print(A0);
  lcd.print("---");
  
  lcd.print(millis()/100);
  
  delay(100);
}
