#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int turnogiocatore = 0;
int turnopartita = 0;
int ngio1 = 0;
int ngio2 = 0;
int punteggioobiettivo = 30;
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
  if (bottone < 400)  return DOWN;
  if (bottone < 600)  return LEFT;
  if (bottone < 920)  return SELECT;
  return NONE;
}

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("Angela Game");
  delay(3000);
}


void aspetta()
{
  btnpremuto = BottonePremuto();
  while (btnpremuto != SELECT)
  {
    btnpremuto = BottonePremuto();
  }
}

void UPPremuto()
{
  if (BottonePremuto() == UP)
  {
    while (BottonePremuto() == UP)
    {  }
    punteggioobiettivo++;
    lcd.setCursor(7, 1);
    lcd.print(punteggioobiettivo);
  }
}

void DOWNPremuto()
{
  if (BottonePremuto() == DOWN)
  {
    while (BottonePremuto() == DOWN)
    {  }
    punteggioobiettivo--;
    lcd.setCursor(7, 1);
    lcd.print(punteggioobiettivo);
  }
}

void RIGHTPremuto()
{
  if (BottonePremuto() == RIGHT)
  {
    while (BottonePremuto() == RIGHT)
    {  }
    punteggioobiettivo += 10;
    lcd.setCursor(7, 1);
    lcd.print(punteggioobiettivo);
  }
}

void LEFTPremuto()
{
  if (BottonePremuto() == LEFT)
  {
    while (BottonePremuto() == LEFT)
    {  }
    punteggioobiettivo -= 10;
    lcd.setCursor(7, 1);
    lcd.print(punteggioobiettivo);
  }
}

void controlloselezione()
{
  UPPremuto();
  DOWNPremuto();
  RIGHTPremuto();
  LEFTPremuto();
}

void sceltapunteggio()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scelta Punteggio");
  lcd.setCursor(7, 1);
  lcd.print(punteggioobiettivo);
  bool finito = false;

  while (!finito)
  {
    controlloselezione();
    if(BottonePremuto() == SELECT)
    {
      turnopartita = 1;
      finito = true;
    }
  }
}

void inizia()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Inizio gioco");
  aspetta();
}


void loop() {
  // put your main code here, to run repeatedly:
  if (turnopartita == 0)
  {
    inizia();
    sceltapunteggio();
  }
}
