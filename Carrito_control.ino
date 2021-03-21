#include <Servo.h>

Servo servo_exterior;
Servo servo_interior;
int Pin_Motor_Der_A = 8;
int Pin_Motor_Der_B = 9;
int Pin_Motor_Izq_A = 10;
int Pin_Motor_Izq_B = 11;
int inicio = 0;
int fin = 90;
int tiempo=0;
void setup() {
  
  Serial.begin(9600);
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);
  servo_exterior.attach(13);
  servo_interior.attach(12);
  servo_exterior.write(fin);
  servo_interior.write(inicio);

}

void loop() {

  if (Serial.available()) {
     char dato= Serial.read();
     if(dato=='s')
     {
        Mover_Adelante();
        tiempo=0;
     }
     else if(dato=='w')
     { 
        Mover_Retroceso();
        tiempo=0;
     }
     else if(dato=='a')
     { 
        Mover_Derecha();
        tiempo=0;
     }
     else if(dato=='d')
     { 
        Mover_Izquierda();
        tiempo=0;
     }
     else if(dato=='r')
     {
        Soltar_pelota();
        tiempo=0;   
     }
   
  }

  if(tiempo<200) // 100 cilcos de 1ms 
  {    
    tiempo=tiempo+1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    Mover_Stop();
  }
  
  
  delay(1); //pasusa de 1ms por ciclo
  
}

void Mover_Adelante()
{
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
void Mover_Retroceso()
{
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
}
void Mover_Derecha()
{
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  digitalWrite (Pin_Motor_Izq_A,HIGH);
  digitalWrite (Pin_Motor_Izq_B,LOW);
}
void Mover_Izquierda()
{
  digitalWrite (Pin_Motor_Der_A,HIGH);
  digitalWrite (Pin_Motor_Der_B,LOW);
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
}
void Mover_Stop()
{
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
void Soltar_pelota()
{
 servo_exterior.write(inicio);
 delay(1500);
 servo_exterior.write(fin);
 delay(1000);
 servo_interior.write(fin);
 delay(1500);
 servo_interior.write(inicio); 
}
