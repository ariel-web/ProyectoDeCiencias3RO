#include <SoftwareSerial.h>
#include <Servo.h>

// CONEXIONES PARA EL BLUETOOTH.

int bluetoothTx = 2;
int bluetoothRx = 3;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

// MOTOR 1.

int Motor1A = 5;
int Motor1B = 6;

// MOTOR 2.

int Motor2A = 9;
int Motor2B = 10;

void setup ()
{
bluetooth.begin(115200);
bluetooth.print("$$$");
delay(100);
bluetooth.println("U,9600,N");
bluetooth.begin(9600);

pinMode( Motor1A, OUTPUT );
pinMode( Motor2A, OUTPUT );
pinMode( Motor1B, OUTPUT );
pinMode( Motor2B, OUTPUT );

digitalWrite( Motor1A, LOW );
digitalWrite( Motor2A, LOW );
digitalWrite( Motor1B, LOW );
digitalWrite( Motor2B, LOW );
}

int flag1 = -1;
int flag2 = -1;
int rc1 = 0;
int rc2 = 0;
int rc3 = 0;
int contador = 1;

void loop() {

if(bluetooth.available()) {
  
  char toSend = (char)bluetooth.read();
    
  if(toSend == 'S') {
    
    flag1 = 0;
    flag2 = 0;
    
    digitalWrite( Motor1A, LOW);
    analogWrite( Motor1B, LOW);
    
    digitalWrite( Motor2A, LOW),
    analogWrite( Motor2B, LOW);
  
  }

    if( toSend == '3') {
 
      if (flag1 != 2) {
      // ESTOS HARAN QUE VAYA PARA ADELANTE EL CARRITO.
        flag1 = 2;
        flag2 = 3;
        if(contador != 3 ){
          if(contador == 2){
            contador = 3;
            digitalWrite( Motor1A, HIGH);
            analogWrite( Motor1B, 0 );
            digitalWrite( Motor2A, HIGH);
            analogWrite( Motor2B, 0 );
            delay(2000);
            digitalWrite( Motor1A, LOW);
            analogWrite( Motor1B, 0 );
            digitalWrite( Motor2A, LOW);
            analogWrite( Motor2B, 0 );
          }else {
            if(contador == 1){
              contador = 3;
              digitalWrite( Motor1A, HIGH);
              analogWrite( Motor1B, 0 );
              digitalWrite( Motor2A, HIGH);
              analogWrite( Motor2B, 0 );
              delay(4000);
              digitalWrite( Motor1A, LOW);
              analogWrite( Motor1B, 0 );
              digitalWrite( Motor2A, LOW);
              analogWrite( Motor2B, 0 );
            }
          }  

        }


      }
    
  }

    if( toSend == '2') {
   
      if (flag1 != 1) {
      // ESTOS HARAN QUE VAYA PARA ADELANTE EL CARRITO.
        flag1 = 1;
        if(contador != 2 ){
          if(contador == 1){
            contador = 2;
            digitalWrite( Motor1A, HIGH);
            analogWrite( Motor1B, 0 );
            digitalWrite( Motor2A, HIGH);
            analogWrite( Motor2B, 0 );
            delay(2000);
            digitalWrite( Motor1A, LOW);
            analogWrite( Motor1B, 0 );
            digitalWrite( Motor2A, LOW);
            analogWrite( Motor2B, 0 );
          }

        }
      }
      else {
        if(flag1 != 2) {
          // ESTOS HARAN LA REVERSA DEL CARRITO.
            flag1 = 2;
            flag2 = 3;
            if(contador != 2 ){
                if(contador == 3){
                  contador = 2;
                }  
                digitalWrite( Motor1B, HIGH);
                analogWrite( Motor1A, 0 );
                digitalWrite( Motor2B, HIGH);
                analogWrite( Motor2A, 0 );
                delay(2000);
                digitalWrite( Motor1B, LOW);
                analogWrite( Motor1A, 0 );
                digitalWrite( Motor2B, LOW);
                analogWrite( Motor2A, 0 );
              }
      
          } 
      
      }    
  }

  if(toSend == '1') {
    if(flag1 != 2) {
    // ESTOS HARAN LA REVERSA DEL CARRITO.
      flag1 = 2;
      if(contador != 1 ){
          if(contador == 2){
            contador = 1;
            digitalWrite( Motor1B, HIGH);
            analogWrite( Motor1A, 0 );
            digitalWrite( Motor2B, HIGH);
            analogWrite( Motor2A, 0 );
            delay(2000);
            digitalWrite( Motor1B, LOW);
            analogWrite( Motor1A, 0 );
            digitalWrite( Motor2B, LOW);
            analogWrite( Motor2A, 0 );
          }else {
            if(contador == 3){
              contador = 1;
              digitalWrite( Motor1B, HIGH);
              analogWrite( Motor1A, 0 );
              digitalWrite( Motor2B, HIGH);
              analogWrite( Motor2A, 0 );
              delay(4000);
              digitalWrite( Motor1B, LOW);
              analogWrite( Motor1A, 0 );
              digitalWrite( Motor2B, LOW);
              analogWrite( Motor2A, 0 );
            }
          }  

        }

    }
  }
 

  

 
  if( toSend == 'F' || toSend == 'G' || toSend == 'I') {
   
      if (flag1 != 1) {
      // ESTOS HARAN QUE VAYA PARA ADELANTE EL CARRITO.
        flag1 = 1;
        if(contador != 3 ){
          if(contador == 1){
            contador = 2;
          }else {
            if(contador == 2){
              contador = 3;
            }
          }  
          digitalWrite( Motor1A, HIGH);
          analogWrite( Motor1B, 0 );
          digitalWrite( Motor2A, HIGH);
          analogWrite( Motor2B, 0 );
          delay(1000);
          digitalWrite( Motor1A, LOW);
          analogWrite( Motor1B, 0 );
          digitalWrite( Motor2A, LOW);
          analogWrite( Motor2B, 0 );
        }
      }    
  }
  
  if(toSend == 'B' || toSend == 'H' || toSend == 'J') {
    if(flag1 != 2) {
    // ESTOS HARAN LA REVERSA DEL CARRITO.
      flag1 = 2;

      if(contador != 1 ){
          if(contador == 3){
            contador = 2;
          }else {
            if(contador == 2){
              contador = 1;
            }
          }  
          digitalWrite( Motor1B, HIGH);
          analogWrite( Motor1A, 0 );
          digitalWrite( Motor2B, HIGH);
          analogWrite( Motor2A, 0 );
          delay(1000);
          digitalWrite( Motor1B, LOW);
          analogWrite( Motor1A, 0 );
          digitalWrite( Motor2B, LOW);
          analogWrite( Motor2A, 0 );
        }

    }
  }
  
 
  else  {
    if(flag2 != 3) {
      flag2 = 3;
      digitalWrite ( Motor2A, LOW);
      analogWrite ( Motor2B, LOW);  
      digitalWrite ( Motor2B, LOW);
      analogWrite ( Motor2A, LOW);  
    }
  
  }
}
}
