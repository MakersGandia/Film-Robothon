#include <LiquidCrystal.h>

#define COLS 16
#define ROWS 12


LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  Serial.begin(9600);
  lcd.begin(COLS,ROWS);

}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  defaultMouth();
}

void defaultMouth() {
  byte defaultMouthArray[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111};
   
  lcd.createChar(0, defaultMouthArray);

  // Upper col
  lcd.setCursor(5,0);
  lcd.write(byte(0));
  /*lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.setCursor(7,0);
  lcd.write(byte(0));
  lcd.setCursor(8,0);
  lcd.write(byte(0));
  lcd.setCursor(9,0);
  lcd.write(byte(0));*/
  lcd.setCursor(10,0);
  lcd.write(byte(0));

  // Lower Row
  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.setCursor(6,1);
  lcd.write(byte(0));
  lcd.setCursor(7,1);
  lcd.write(byte(0));
  lcd.setCursor(8,1);
  lcd.write(byte(0));
  lcd.setCursor(9,1);
  lcd.write(byte(0));
  lcd.setCursor(10,1);
  lcd.write(byte(0));

} // ()
