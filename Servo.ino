#include <Servo.h>
#define Servo1_pin 12



Servo servo_der, servo_izq;
void setup() {
  // put your setup code here, to run once:
pinMode (Servo1_pin, OUTPUT);
servo_der.attach (Servo1_pin);

}

void loop() {
  // put your main code here, to run repeatedly:
for (int x=0; x<=180;x++){
  servo_der.write(x);
  delay(20);
}
for (int x=180; x>=0;x--){
  servo_der.write(x);
  delay(20);
}
}
