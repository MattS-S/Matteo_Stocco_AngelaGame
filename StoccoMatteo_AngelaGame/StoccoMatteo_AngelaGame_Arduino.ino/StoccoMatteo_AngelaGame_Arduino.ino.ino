#include <LiquidCrystal.h>

boolean blacklightStatus = false;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int SELECT[]  =  {720,760};
int LEFT[]    =  {480,520};
int RIGTH[]   =  {0,20};
int UP[]      =  {120,160};
int DOWN[]    =  {300,350};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("Angela Game");
  delay(1500);
}


void loop() {
  // put your main code here, to run repeatedly:

}
