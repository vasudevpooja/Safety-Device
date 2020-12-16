#include <LiquidCrystal.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
static const int a = 2, b = 3;
static const uint32_t gps_1 = 9600;
TinyGPSPlus gps;
SoftwareSerial pins(a, b);
float latitude, longitude;
void setup()
{
  pins.begin(gps_1);
  Serial.begin(19200);
  pinMode(10,INPUT);
  pinMode(5, OUTPUT);
}
void loop()
{
  int key = digitalRead(10);
  while (pins.available() > 0)
  {
    gps.encode(pins.read());
    if (gps.location.isUpdated())
    {
      latitude = gps.location.lat();
      longitude = gps.location.lng();
    }
    else;
  }
  if(key==1)
  {
    digitalWrite(5,HIGH);
    call();
    digitalWrite(5,LOW);
  }
}
void call()
{
  Serial.begin(9600);
  Serial.println("Calling"); 
  delay(1000);
  pins.println("AT"); 
  updateS();
  pins.println("ATD+ +AAXXXXXXXXXX;");
  updateS();
  delay(40000); 
  pins.println("ATH");
  sms();
  updateS();
}
void sms()
{
    Serial.print("AT+CMGF=1\r");
    delay(100);
    Serial.println("AT+CMGS =\"+918105805044\"");
    delay(100);
    Serial.println("HELP! Location:");
    Serial.println(String("Latitude: ")+String(latitude));
    Serial.println(String("Longitude: ")+String(longitude));
    delay(100);
    Serial.println();
    delay(3000);
}
void updateS()
{
  delay(800);
  while (Serial.available()) 
  {
    pins.write(Serial.read());
  }
  while(pins.available()) 
  {
    Serial.write(pins.read());
  }
}
