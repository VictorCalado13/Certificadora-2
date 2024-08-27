#include <LiquidCrystal_I2C.h>

#define MQ2_ANA 15
#define LDR 4
#define buzzer 25
#define rele 0

float MQ2_leitura, LDR_leitura;
int CO2, FOGO;

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {

  Serial.begin(115200);

  pinMode(buzzer, OUTPUT);
  pinMode(rele, OUTPUT);
  pinMode(MQ2_ANA, INPUT);

  digitalWrite(buzzer, LOW);
  digitalWrite(rele, LOW);

  LCD.init();
  LCD.backlight();
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("Iniciando");
  LCD.setCursor(0, 1);
  LCD.print("Sistemas");

  for (int i = 0; i < 3; i++) {
    delay(500);
    LCD.print(".");
    delay(500);
  }
  LCD.clear();

}

void loop() {

  //Leitura dos dados
  MQ2_leitura = analogRead(MQ2_ANA);
  LDR_leitura = analogRead(LDR);

  CO2 = map(MQ2_leitura, 0, 4095, 0, 100);
  FOGO = map(LDR_leitura, 0, 4095, 100, 0);

  // Impressão dos dados no sistema
  Serial.print("CO2: ");
  Serial.print(CO2, 0);
  Serial.println("%");

  Serial.print("Fogo: ");
  Serial.print(FOGO, 0);
  Serial.println("%");
  Serial.println("---");

  //Condição de incendio
  if (FOGO > 80 || CO2 > 60) {
    LCD.setCursor(0, 0);
    LCD.print("TA PEGANDO FOGO");
    LCD.setCursor(0, 1);
    LCD.print("BIXO!");
    tone(buzzer, 392, 100);
    tone(buzzer, 440, 100);
    digitalWrite(rele, HIGH);
    LCD.clear();
    delay(100);
  } else {

    //Impressão dos dados
    LCD.setCursor(0, 0);
    LCD.print("CO2:  ");
    LCD.setCursor(0, 1);
    LCD.print("Fogo: ");

    LCD.setCursor(6, 0);
    LCD.print(CO2, 0);
    LCD.print("%   ");
    LCD.setCursor(6, 1);
    LCD.print(FOGO, 0);
    LCD.print("%   ");

    delay(500);
  }
}
