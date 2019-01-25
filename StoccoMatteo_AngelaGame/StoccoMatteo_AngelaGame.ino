#include <LiquidCrystal.h>

//int valoredecine = 3;
//int valoreunita = 0;
int turnogiocatore = 0;
int turnopartita = 0;
int numerogiocatore1 = 0;
int numerogiocatore2 = 0;
int punteggioobiettivo = 30;
int punteggiomomentaneo = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Gioco Angela");
  delay(1500);
  Serial.println("Scegli punteggio obiettivo (scrivere nella barra di input)");
}



void inseriscipunteggioobiettivo()
{
  punteggioobiettivo = Serial.parseInt();
  while (punteggioobiettivo < 30)
  {
    if (punteggioobiettivo == 0)
    {
      punteggioobiettivo = Serial.parseInt();
    } else {
      punteggioobiettivo = Serial.parseInt();
      Serial.println("Punteggio obiettivo non valido");
    }
  }
  if ((punteggioobiettivo >= 30) && (punteggioobiettivo < 100))
  {
    Serial.println(punteggioobiettivo);
  }
}



void aggiornamentovariabili()
{
  if (turnopartita % 2 == 1)
  {
    Serial.println(numerogiocatore2);
    punteggiomomentaneo = punteggiomomentaneo + numerogiocatore2;
    Serial.print("Punteggio momentaneo: ");
    Serial.println(punteggiomomentaneo);
    turnogiocatore = 0;
    turnopartita++;
  } else {
    Serial.println(numerogiocatore1);
    punteggiomomentaneo = punteggiomomentaneo + numerogiocatore1;
    Serial.print("Punteggio momentaneo: ");
    Serial.println(punteggiomomentaneo);
    turnogiocatore = 1;
    turnopartita++;
  }
}



void controllogiocatore()
{
  if (turnopartita % 2 == 1)
  {
    while ((numerogiocatore2  == 7 - numerogiocatore1) || (numerogiocatore2  == numerogiocatore1) || (numerogiocatore2 > 6) || (numerogiocatore2 <= 0))
    {
      numerogiocatore2 = Serial.parseInt();
      if ((numerogiocatore2  == 7 - numerogiocatore1) || (numerogiocatore2  == numerogiocatore1) || (numerogiocatore2 > 6))
      {
        Serial.println("Numero scelto non valido");
      }
    }
  } else {
    while ((numerogiocatore1  == 7 - numerogiocatore2) || (numerogiocatore1  == numerogiocatore2) || (numerogiocatore1 > 6) || (numerogiocatore1 <= 0))
    {
      numerogiocatore1 = Serial.parseInt();
      if ((numerogiocatore1  == 7 - numerogiocatore2) || (numerogiocatore1  == numerogiocatore2) || (numerogiocatore1 > 6))
      {
        Serial.println("Numero scelto non valido");
      }
    }
  }
}


void turnozero()
{
  numerogiocatore1 = Serial.parseInt();
  while ((numerogiocatore1 <= 0) || (numerogiocatore1 > 7))
  {
    if (numerogiocatore1 == 0)
    {
      numerogiocatore1 = Serial.parseInt();
    }
    if (numerogiocatore1 > 7 || (numerogiocatore1 < 0)) {
      numerogiocatore1 = Serial.parseInt();
      Serial.println("Numero scelto non valido");
    }
  }

  if ((numerogiocatore1 > 0) && (numerogiocatore1 < 7))
  {
    aggiornamentovariabili();
  } else if (numerogiocatore1 == 7)
  {
    //se vuole inserire lo 0 deve usare il 7
    numerogiocatore1 = 0;
    aggiornamentovariabili();
  }
}

void metodoswitch()
{
  if (turnogiocatore % 2 == 1)
    switch (numerogiocatore1)
    {
      case 1:
      case 6:
        controllogiocatore();
        aggiornamentovariabili();
      case 2:
      case 5:
        controllogiocatore();
        aggiornamentovariabili();
      case 3:
      case 4:
        controllogiocatore();
        aggiornamentovariabili();
    } else {

    switch (numerogiocatore2)
    {
      case 1:
      case 6:
        controllogiocatore();
        aggiornamentovariabili();
      case 2:
      case 5:
        controllogiocatore();
        aggiornamentovariabili();
      case 3:
      case 4:
        controllogiocatore();
        aggiornamentovariabili();
    }
  }
}

void sceltagiocatore()
{
  if (turnopartita == 0)
  {
    turnozero();
  } else {
    if (turnogiocatore == 1)
    {
      numerogiocatore2 = Serial.parseInt();
      metodoswitch();
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  if (turnopartita == 0)
  {
    inseriscipunteggioobiettivo();
  }
  sceltagiocatore();

}
