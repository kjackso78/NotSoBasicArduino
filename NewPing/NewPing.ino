#include <NewPing.h>
#include <Servo.h>
Servo myservo;
#define TRIGGER_PIN 7
#define ECHO_PIN 6
#define MAX_DISTANCE 200

int cm = 0;
NewPing myHCSR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
 Serial.begin(9600);
 myservo.attach(9);
} 
void loop() {
    cm = myHCSR04.ping_cm();
     Serial.println(cm);
     delay(50); 
    if ( cm != 0 && cm < 150)
  {
    if (cm < 10) {
      myservo.write(100);
    }
    if (cm > 10) {
       myservo.write(80);
    }
  }
}
