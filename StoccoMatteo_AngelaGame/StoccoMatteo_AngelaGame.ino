#include <LiquidCrystal.h>

//int valoredecine = 3;
//int valoreunita = 0;
int numerogiocatore1 = 0;
int numerogiocatore2 = 0;
int punteggioobiettivo = 30;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Gioco Angela");
  delay(2000);
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

void sceglipunteggioobiettivo()
{
  Serial.println("Scegli punteggio obiettivo (seleziona decine)");
  delay(500);
  Serial.println(punteggioobiettivo);
  bool finito = false;
}
void loop() {
  // put your main code here, to run repeatedly:
  inseriscipunteggioobiettivo();

}
