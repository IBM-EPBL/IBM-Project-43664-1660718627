
#define BLYNK_PRINT Serial
#include <Ultrasonic.h>
#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleMKR1000.h>

char auth[] = "hftydytfuygiuguyfytced9";
char ssid[] = "justdo";
char pass[] = "phuhbjjnk";

BlynkTimer timer;
int distance = 0;
int thresh[3] = {25, 50, 75};
Ultrasonic ultrasonic(12, 13);

WidgetLED green(V1);
WidgetLED orange(V2);
WidgetLED red(V3);



void setup()
{
  
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  distance = ultrasonic.distanceRead();
  Serial.println(distance);
  Blynk.run();

  if(distance<thresh[0]){
    green.on();
    }
  else if(distance<thresh[1])
    green.on();
    orange.on();
  }
  else if(distance<thresh[2])
    green.on();
    orange.on();
    red.on();
  }
  else{
    green.off();
    orange.off();
    red.off();
  delay(100);
}
