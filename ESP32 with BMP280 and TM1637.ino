#include <TM1637Display.h>
#include <Adafruit_BMP280.h>
 
#define CLK 19
#define DIO 18
 
TM1637Display display(CLK, DIO);
Adafruit_BMP280 bmp;
 
int tempik;
 
void setup() {
  Serial.begin(115200);
  Serial.println("Adafruit BMP280 demo!");
  if (!bmp.begin(0x76))
  {
    Serial.println("Gagal Menemukan BMP280, Mohon Cek Sambungan Kabel I2C");
    while (1);
  }
  Serial.println("AHT10 or AHT20 found");
}
 
void loop(){
  display.setBrightness(0x0f);
  Serial.print(bmp.readTemperature());
  tempik = bmp.readTemperature()*100;
  display.showNumberDec(tempik, false);
  delay(2500);
}
