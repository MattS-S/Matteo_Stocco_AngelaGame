#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int turnogiocatore = 0;
int turnopartita = 0;
int ngio1 = 1;
int ngio2 = 1;
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

//metodo che controlla il bottone premuto
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
  lcd.setCursor(0, 0);
  lcd.print("--Angela  Game--");
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
//Bottone UP
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
//Bottone Down
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
//Bottone Right
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
//Bottone Left
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

//Sceglie il punteggio obiettivo
void sceltapunteggio()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scelta Punteggio");
  lcd.setCursor(0, 1);
  lcd.print("(-)");
  lcd.setCursor(7, 1);
  lcd.print(punteggioobiettivo);
  lcd.setCursor(13, 1);
  lcd.print("(+)");
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

//Inizio Gioco
void inizia()
{
  lcd.setCursor(2, 1);
  lcd.print("Inizio gioco");
  aspetta();
  delay(1000);
}

//SCELTA GIOCATORE
//Primo turno
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
      finito = true;
      delay(1000);
    }
  }
}
//Turni generali
void turno()
{
  if (punteggiomomentaneo < punteggioobiettivo)
  {
    messaggio();
    bool finito = false;
    while (!finito)
    {
      NumeroGiocatore();
      if ((BottonePremuto() == SELECT))
      {
        if (controllogiocatore() == false)
        {
          messaggio();
          NumeroGiocatore();
        } else {
          aggiornavariabili();
          finito = true;
        }
      }
    }
  } else {
    vittoria();
    delay(1000);
  }
}



//Scelta giocatore 1
void Giocatore1()
{
  if (turnogiocatore % 2 == 0)
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
      if (turnogiocatore == 0)
      {
        if (ngio1 > 0)
        {
          while (BottonePremuto() == DOWN)
          {  }
          ngio1--;
          lcd.setCursor(7, 1);
          lcd.print(ngio1);
        }
      } else {
        if (ngio1 > 1)
        {
          while (BottonePremuto() == DOWN)
          {  }
          ngio1--;
          lcd.setCursor(7, 1);
          lcd.print(ngio1);
        }
      }
    }
  }
}

//Scelta giocatore 2
void Giocatore2()
{
  if (turnogiocatore % 2 == 1)
  {
    if (BottonePremuto() == UP)
    {
      if (ngio2 < 6)
      {
        while (BottonePremuto() == UP)
        {  }
        ngio2++;
        lcd.setCursor(7, 1);
        lcd.print(ngio2);
      }
    }
    if (BottonePremuto() == DOWN)
    {
      if (ngio2 > 1)
      {
        while (BottonePremuto() == DOWN)
        {  }
        ngio2--;
        lcd.setCursor(7, 1);
        lcd.print(ngio2);
      }
    }
  }
}

//Il giocatore può scegliere il numero che vuole giocare
void NumeroGiocatore()
{
  Giocatore1();
  Giocatore2();
}

//Controlla se il numero del giocatore è valido
bool controllogiocatore()
{
  bool valido = true;
  if (turnogiocatore % 2 == 1)
  {
    if ((ngio2  == 7 - ngio1) || (ngio2  == ngio1))
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      valido = false;
      lcd.print("Numero invalido");
      delay(1500);
    }
  }
  else if (turnogiocatore % 2 == 0) {
    if ((ngio1  == 7 - ngio2) || (ngio1  == ngio2))
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      valido = false;
      lcd.print("Numero invalido");
      delay(1500);
    }
  }
  return valido;
}


//Messaggio di inizio scelta
void messaggio()
{
  if (turnogiocatore % 2 == 1)
  {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Gioca G2");
    delay(2000);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("G2: " + String(punteggiomomentaneo) + " - " + String(punteggioobiettivo));
    lcd.setCursor(0, 1);
    lcd.print("(-)");
    lcd.setCursor(7, 1);
    lcd.print(ngio2);
    lcd.setCursor(13, 1);
    lcd.print("(+)");
  } else {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Gioca G1");
    delay(2000);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("G1: " + String(punteggiomomentaneo) + " - " + String(punteggioobiettivo));
    lcd.setCursor(0, 1);
    lcd.print("(-)");
    lcd.setCursor(7, 1);
    lcd.print(ngio1);
    lcd.setCursor(13, 1);
    lcd.print("(+)");
  }
}

//Aggiorna le variabili dopo una giocata
void aggiornavariabili()
{
  if (turnogiocatore % 2 == 1)
  {
    punteggiomomentaneo += ngio2;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Punteggio totale");
    lcd.setCursor(7, 1);
    lcd.print(punteggiomomentaneo);
    delay(1500);
    turnogiocatore++;
    ngio1 = 1;
  } else {
    punteggiomomentaneo += ngio1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Punteggio totale");
    lcd.setCursor(7, 1);
    lcd.print(punteggiomomentaneo);
    delay(1500);
    turnogiocatore++;
    ngio2 = 1;
  }
}

//PARTE DEL GIOCATORE
void sceltagiocatore()
{
  if (turnogiocatore == 0)
  {
    turnozero();
  } else {
    turno();
  }
}

//Vittoria
void vittoria()
{
  if (punteggioobiettivo == punteggiomomentaneo)
  {
    if (turnogiocatore % 2 == 1)
    {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Giocatore 1");
      lcd.setCursor(3, 1);
      lcd.print("Hai vinto!!");
    } else {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Giocatore 2");
      lcd.setCursor(3, 1);
      lcd.print("Hai vinto!!");
    }
  } else if (punteggioobiettivo < punteggiomomentaneo)
  {
    if (turnogiocatore % 2 == 1)
    {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Giocatore 2");
      lcd.setCursor(3, 1);
      lcd.print("Hai Vinto!!");
    } else {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Giocatore 1");
      lcd.setCursor(3, 1);
      lcd.print("Hai Vinto!!");
    }
  }
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
    sceltagiocatore();
  }
}
