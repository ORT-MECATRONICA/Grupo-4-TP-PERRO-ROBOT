#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C de la pantalla LCD (puede variar: 0x27 o 0x3F)
// Si no estás seguro, usá el código scanner que ya tenés
#define LCD_ADDR 0x27  

// Creamos objeto LCD: (dirección, columnas, filas)
LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

// Pines I2C1
#define SDA_PIN 21
#define SCL_PIN 22

void setup() {
  // Iniciar comunicación serie
  Serial.begin(115200);

  // Inicializamos I2C1 en los pines definidos
  Wire.begin(SDA_PIN, SCL_PIN);

  // Inicializamos la pantalla LCD
  lcd.init();
  lcd.backlight();  // Encender luz de fondo

  // Mensaje inicial
  lcd.setCursor(0, 0);
  lcd.print("   Hola, Roman!");


  Serial.println("Pantalla LCD inicializada correctamente.");
}

void loop() {
  // Animación simple: contador en la segunda línea
  static int contador = 0;

  lcd.setCursor(0, 1);
  lcd.print("Contador: ");
  lcd.print(contador);
  lcd.print("   ");  // Borra posibles restos

  contador++;
  if (contador > 999) contador = 0;

  delay(1000);
}
