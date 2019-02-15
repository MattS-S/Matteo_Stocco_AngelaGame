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

//ASPETTA
void aspetta()
{
  btnpremuto = BottonePremuto();
  while (btnpremuto != SELECT)
  {
    btnpremuto = BottonePremuto();
  }
}

//SCELTA OBIETTIVO
void UPPremuto()
{
  if (BottonePremuto() == UP)
  {
    if (punteggioobiettivo < 99)
    {
      while (BottonePremuto() == UP)
      {  }
      punteggioobiettivo++;
      lcd.setCursor(7, 1);
      lcd.print(punteggioobiettivo);
    }
  }
}

void DOWNPremuto()
{
  if (BottonePremuto() == DOWN)
  {
    if (punteggioobiettivo > 30)
    {
      while (BottonePremuto() == DOWN)
      {  }
      punteggioobiettivo--;
      lcd.setCursor(7, 1);
      lcd.print(punteggioobiettivo);
    }
  }
}

void RIGHTPremuto()
{
  if (BottonePremuto() == RIGHT)
  {
    if (punteggioobiettivo < 90)
    {
      while (BottonePremuto() == RIGHT)
      {  }
      punteggioobiettivo += 10;
      lcd.setCursor(7, 1);
      lcd.print(punteggioobiettivo);
    }
  }
}

void LEFTPremuto()
{
  if (BottonePremuto() == LEFT)
  {
    if (punteggioobiettivo >= 40)
    {
      while (BottonePremuto() == LEFT)
      {  }
      punteggioobiettivo -= 10;
      lcd.setCursor(7, 1);
      lcd.print(punteggioobiettivo);
    }
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
    if (BottonePremuto() == SELECT)
    {
      turnopartita = 1;
      finito = true;
      delay(1000);
    }
  }
}

void inizia()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Inizio gioco");
  aspetta();
  delay(1000);
}

//SCELTA GIOCATORE
void turnozero()
{
  messaggio();
  bool finito = false;
  while (!finito)
  {
    NumeroGiocatore();
    if (BottonePremuto() == SELECT)
    {
      aggiornavariabili();
      turnogiocatore++;
      finito = true;
      delay(1000);
    }
  }
}

void NumeroGiocatore()
{
  if (BottonePremuto() == UP)
  {
    if (ngio1 < 6)
    {
      while (BottonePremuto() == UP)
      {  }
      ngio1++;
      lcd.setCursor(7, 1);
      lcd.print(ngio1);
    }
  }
  if (BottonePremuto() == DOWN)
  {
    if (ngio1 > 0)
    {
      while (BottonePremuto() == DOWN)
      {  }
      ngio1--;
      lcd.setCursor(7, 1);
      lcd.print(ngio1);
    }
  }
}

void messaggio()
{
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Gioca G1");
  delay(1500);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Scegli numero");
  lcd.setCursor(7, 1);
  lcd.print(ngio1);
}

void aggiornavariabili()
{
  if (turnogiocatore % 2 == 1)
  {
    punteggiomomentaneo += ngio2;
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Punteggio");
    lcd.setCursor(7,1);
    lcd.print(punteggiomomentaneo);
    delay(1500);
    turnogiocatore++;
    } else {
    punteggiomomentaneo += ngio1;
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Punteggio");
    lcd.setCursor(7,1);
    lcd.print(punteggiomomentaneo);
    delay(1500);
    turnogiocatore++;
  }
}

void sceltagiocatore()
{

}


void loop() {
  // put your main code here, to run repeatedly:
  if (turnopartita == 0)
  {
    inizia();
    sceltapunteggio();
  }
  else if (turnopartita == 1)
  {
    turnozero();
  }
}
