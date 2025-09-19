//Grupo 4 Otero - Fraccaro - Ponczyk - Nisim

#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x27  

#define SDA_PIN 21   // Pin SDA I2C1
#define SCL_PIN 22   // Pin SCL I2C1
#define MQ4_PIN 32
#define MQ9_PIN 33
#define LDR_PIN 34
#define BOTON1 18
#define BOTON2 19
#define BOTON3 21
#define BOTON4 22
#define BOTON5 23
#define LED1 25
#define LED2 26
#define LED3 27

int lecturaMQ4;
int valorMQ4; 
int lecturaMQ9;
int valorMQ9;
Adafruit_AHTX0 aht;
LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

 
#define RST 0
#define P1 1
#define P2 2
#define P3 3
#define P4 4
#define P5 5
#define ESPERA1 10
#define ESPERA2 14
#define ESPERA3 15
#define ESPERA4 28
#define ESPERA5 23


void setup() {
  Serial.begin(115200);
  pinMode(BOTON1,INPUT_PULLUP);
  pinMode(BOTON2,INPUT_PULLUP);
  pinMode(BOTON3,INPUT_PULLUP);
  pinMode(BOTON4,INPUT_PULLUP);
  pinMode(BOTON5,INPUT_PULLUP);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);

  
  Wire.begin(SDA_PIN, SCL_PIN);
  lcd.init();
  lcd.backlight(); 
  if (!aht.begin(&Wire)) {
    Serial.println("❌ Error: No se detectó el AHT10. Revisá las conexiones.");
    while (1);
  }


  //EN EL LOOP
  //GAS
  lecturaMQ4 = analogRead(MQ4_PIN);  // Lee valor analógico
  valorMQ4 = map(lecturaMQ4, 0, 4095, 0, 100);
  lecturaMQ9 = analogRead(MQ9_PIN);
  valorMQ9 = map(lecturaMQ9,0,4095,0,100);
  Serial.print("Valor MQ-4: ");
  Serial.print(valorMQ4);
  Serial.println("%");
  Serial.print("Valor MQ-9: ");
  Serial.print(valorMQ9);
  Serial.println("%");

  //LDR
  int lecturaLDR = analogRead(LDR_PIN);  // Lee valor analógico
  int valorLDR = map(lecturaLDR, 0, 4095, 0, 100);
  Serial.print("Valor LDR: ");
  Serial.print(valorLDR);
  Serial.println("%");

  //TEMPERATURA
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  Serial.print("🌡️  Temperatura: ");
  Serial.print(temp.temperature);
  Serial.println(" °C");
  Serial.print("💧 Humedad: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" %");

  //DISPLAY
  lcd.setCursor(0, 1);
  lcd.print("Contador: ");
}

void loop() { 

  
}
