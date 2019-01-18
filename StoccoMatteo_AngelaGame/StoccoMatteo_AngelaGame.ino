#include <LiquidCrystal.h>

//int valoredecine = 3;
//int valoreunita = 0;
int turnogiocatore = 0;
int turnopartita = 0;
int numerogiocatore1 = 0;
int numerogiocatore2 = 0;
int punteggioobiettivo = 30;

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
  while (punteggioobiettivo == 0)
  {
    punteggioobiettivo = Serial.parseInt();
  }
  if ((punteggioobiettivo >= 30) && (punteggioobiettivo < 100))
  {
    Serial.println(punteggioobiettivo);
  } else {
    Serial.println("Punteggio obiettivo non valido");
  }
}

void sceltagiocatore()
{
  if (turnopartita == 0)
  {
    numerogiocatore1 = Serial.parseInt();
    while (numerogiocatore1 == 0)
    {
      numerogiocatore1 = Serial.parseInt();
    }
    if ((numerogiocatore1 >= 0) && (numerogiocatore1 < 7))
    {
      Serial.println(numerogiocatore1);
    } else {
      Serial.println("Numero scelto non valido");
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  inseriscipunteggioobiettivo();
  sceltagiocatore();

}
