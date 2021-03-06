#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define D0 13
#define D1 10

char auth[] = "XXXXXXXXXXXXXXXXXXXXXX"; //Token key
char server[] = "oasiskit.com";
char ssid[] = "XXXXXXXX";
char pass[] = "XXXXXXXX";
int port = 8080;
char led1 = D0;
char led2 = D1;

void setup() {
  Serial.begin(115200);
  Serial.println("กำลังเชื่อมต่อไปที่ Blynk Server");
  pinMode(D0, OUTPUT); //กำหนดโหมด ว่าเป็น INPUT หรือ OUTPUT
  pinMode(D1, OUTPUT);
  WiFi.begin(ssid, pass); //เชื่อมต่อ WiFi
  Blynk.config(auth, server, port); //กำหนด Token key , ชื่อ Server และ port
  Blynk.connect(); //เชื่อมต่อไปยัง Blynk
}

BLYNK_CONNECTED() {  // ฟังก์ชันนี้ทำงานเมื่อต่อ Blynk ได้ 
  Serial.println("App Blynk ทำงาน!");
}

void loop() {
  
  Blynk.run();


}
