#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int turnogiocatore = 0;
int turnopartita = 0;
int numerogiocatore1 = 0;
int numerogiocatore2 = 0;
int punteggioobiettivo = 0;
int punteggiomomentaneo = 0;

int btnpremuto = 0;
int bottone  = 0;

int RIGHT = 0;
int UP  = 1;
int DOWN = 2;
int LEFT  = 3;
int SELECT = 4;
int NONE = 5;

int BottonePremuto() {
  bottone = analogRead(0);
  if (bottone > 1000) return NONE;
  if (bottone < 50)   return RIGHT;
  if (bottone < 250)  return UP;
  if (bottone < 450)  return DOWN;
  if (bottone < 600)  return LEFT;
  if (bottone < 920)  return SELECT;
  return NONE;
}

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("Angela Game");
}

void loop() {
  // put your main code here, to run repeatedly:

}
