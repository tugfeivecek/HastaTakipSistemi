#define USE_ARDUINO_INTERRUPTS true    // Pulse kütüphanesinin daha doğru ölçüm yapabilmesi için bu ayarı etkinleştiriyoruz
#include <PulseSensorPlayground.h> //Yazının başında bilgisayarımıza kurmuş olduğumuz Pulse Playground kütüphanesini ekliyoruz.
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd (0x27,16,2);
int nabiz; //İçinde dakikadaki nabzı tutacağımız değişkeni oluşturuyoruz.

const int PulseWire = 0; // Pulse sensörümüzü bağlamış olduğumuz Analog pinini belirliyoruz.
const int LED13 = 13; // Arduino üzerindeki ledin nabzımızla birlikte yanıp sönmesi için bu değişkeni 13 numaralı pin olarak ayarlıyoruz.
int Threshold = 510; // Yazının başında belirlemiş olduğumuz eşik değerini bu değişkene atıyoruz.

PulseSensorPlayground pulseSensor; //Sensörümüzü kodumuzda kullanabilmek için onu obje olarak oluşturuyoruz.

void setup() {
  
  Serial.begin(9600);  //Bilgisayrımızla olan seri iletişimi başlatıyoruz.
  
  pulseSensor.analogInput(PulseWire); //Pulse sensörünün bağlıu olduğu pini belirliyoruz.
  pulseSensor.blinkOnPulse(LED13);       //arduino üzerindeki ledin nabzımızla yanıp sönmesini istediğimizi söylüyoruz.
  pulseSensor.setThreshold(Threshold); //Değişkene atamış olduğumuz eşik değerini uyguluyoruz.
  // put your setup code here, to run once:

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
 
  lcd.begin();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.println("Nabziniz");
  delay(1000);
 
  
  if (pulseSensor.begin()) {
    
  } //Pulse sensörü başarıyla başlatılırsa bilgisayara mesaj gönderioyoruz.

}

void loop() {

 
  // put your main code here, to run repeatedly:
  if (pulseSensor.sawStartOfBeat()) { //Eğer nabız algılarsak
    nabiz = pulseSensor.getBeatsPerMinute(); //Dakikadaki nabzı nabiz değişkenine kaydediyoruz.
    Serial.println(nabiz);
    

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nabziniz");
    lcd.setCursor(0, 1);
    lcd.print(nabiz);   
    delay(1000);

  }


  delay(20); //20 milisaniye bekletiyoruyuz.

}
