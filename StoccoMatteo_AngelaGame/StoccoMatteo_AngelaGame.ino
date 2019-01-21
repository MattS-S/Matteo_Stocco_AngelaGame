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

void sceltagiocatore()
{
  if (turnopartita == 0)
  {
    numerogiocatore1 = Serial.parseInt();
    while ((numerogiocatore1 <= 0) || (numerogiocatore1 > 6))
    {
      if (numerogiocatore1 == 0)
      {
        numerogiocatore1 = Serial.parseInt();
      } else {
        numerogiocatore1 = Serial.parseInt();
        Serial.println("Numero scelto non valido");
      }
    }
    if ((numerogiocatore1 >= 0) && (numerogiocatore1 < 7))
    {
      Serial.println(numerogiocatore1);
      punteggiomomentaneo = punteggiomomentaneo + numerogiocatore1;
      Serial.print("Punteggio momentaneo: ");
      Serial.println(punteggiomomentaneo);
      turnogiocatore = 1;
      turnopartita++;
    }
  } else {
    if (turnogiocatore == 1)
    {
      numerogiocatore2 = Serial.parseInt();
      switch (numerogiocatore1)
      {
        case 1:
        case 6:
          while ((numerogiocatore2  == 1) || (numerogiocatore2  == 6) || (numerogiocatore2 > 6) || (numerogiocatore2 <= 0))
          {
            numerogiocatore2 = Serial.parseInt();
            if ((numerogiocatore2  == 1) || (numerogiocatore2  == 6) || (numerogiocatore2 > 6))
            {
              Serial.println("Numero scelto non valido");
            }
          }
          Serial.println(numerogiocatore2);
          punteggiomomentaneo = punteggiomomentaneo + numerogiocatore2;
          Serial.print("Punteggio momentaneo: ");
          Serial.println(punteggiomomentaneo);
          turnogiocatore = 0;
          turnopartita++;
          
        case 2:
        case 5:
          while ((numerogiocatore2  == 2) || (numerogiocatore2  == 5) || (numerogiocatore2 > 6) || (numerogiocatore2 <= 0))
          {
            numerogiocatore2 = Serial.parseInt();
            if ((numerogiocatore2  == 2) || (numerogiocatore2  == 5) || (numerogiocatore2 > 6))
            {
              Serial.println("Numero scelto non valido");
            }
          }
          Serial.println(numerogiocatore2);
          punteggiomomentaneo = punteggiomomentaneo + numerogiocatore2;
          Serial.print("Punteggio momentaneo: ");
          Serial.println(punteggiomomentaneo);
          turnogiocatore = 0;
          turnopartita++;

        case 3:
        case 4:
          while ((numerogiocatore2  == 3) || (numerogiocatore2  == 4) || (numerogiocatore2 > 6) || (numerogiocatore2 <= 0))
          {
            numerogiocatore2 = Serial.parseInt();
            if ((numerogiocatore2  == 3) || (numerogiocatore2  == 4) || (numerogiocatore2 > 6))
            {
              Serial.println("Numero scelto non valido");
            }
          }
          Serial.println(numerogiocatore2);
          punteggiomomentaneo = punteggiomomentaneo + numerogiocatore2;
          Serial.print("Punteggio momentaneo: ");
          Serial.println(punteggiomomentaneo);
          turnogiocatore = 0;
          turnopartita++;
      }
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
