
#include <ESP8266WiFi.h>                                                // esp8266 library
#include <FirebaseArduino.h>                                             // firebase library

#define FIREBASE_HOST "pulseproject-751bd.firebaseio.com"                         // the project name address from firebase id
#define FIREBASE_AUTH "qoVqGBVa3Q8AfpdAcfpG880NfN84sfKBwEvVLzzt"                    // the secret key generated from firebase
#define WIFI_SSID "tugfe"                                          // input your home or public wifi name 
#define WIFI_PASSWORD "tugfe1997"                                    
                                                       
void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                                      //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                                       // connect to firebase
                                         //send initial string of led status
}
int sayac = 0;

void loop() {
  
  
  if(Serial.available()){
     
     String veri = Serial.readString();
     Serial.println(veri);
     Firebase.setString(String(sayac), String(veri));
     sayac++;    
     
   }
  
  
}
