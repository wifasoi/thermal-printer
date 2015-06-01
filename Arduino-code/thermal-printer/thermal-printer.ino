//Stepper motor pin
#define Steps   200
#define Speed   30  //in rpm (revolution per minute)
#define Enable  11
#define Fase1   12
#define Fase2   13

//thermal-printer
#define D_leng  832
#define Data    3
#define Clk     4
#define STR     5
#define Print1  6  //per limitare la corrente
#define Print2  7  //si aziona solo una sezione
#define Print3  8  //di stampa alla volta
#define Print4  9  //(sono attivi a livello basso)
#define Print5  10
#define therm   A1
#define P_time  50 //print time in ms
#define D_time  10  //tempo di trasmissione in ms
#define Step_ln 1  //step necessari per avanzare di linea#define Print3

#include <Stepper.h>

boolean unalinea[D_leng-1];
Stepper motore = Stepper(Steps, Fase1, Fase2);



void setup() {
  //Stepper motor
  pinMode(Enable, OUTPUT);
  pinMode(Fase1,  OUTPUT);
  pinMode(Fase2,  OUTPUT); 
  
  motore.setSpeed(Speed);                          //default speed
  
  //
  

}

void loop() {
  

}

void newLN(){
   motore.step(Step_ln); 
}

void backLN(){
   motore.step(-Step_ln); 
}

void writeLN(boolean line[]){
  digitalWrite(Clk, LOW);
  
  for(int i=0; i < D_leng; i++){
    digitalWrite(Data, line[i]);
    delay(D_time); 
    digitalWrite(Clk, HIGH);
    delay(D_time);
    digitalWrite(Clk, LOW);
  }
}
  
void PrintLN(boolean line[]){
  digitalWrite(Print1, HIGH);
  digitalWrite(Print2, HIGH);
  digitalWrite(Print3, HIGH);
  digitalWrite(Print4, HIGH);
  digitalWrite(Print5, HIGH);
  
  writeLN(line);  //verifivare (cose con la & e accessori  )
  
  digitalWrite(Print1, LOW);
  delay(P_time);
  digitalWrite(Print1, HIGH);
  
  digitalWrite(Print2, LOW);
  delay(P_time);
  digitalWrite(Print2, HIGH);
  
  digitalWrite(Print3, LOW);
  delay(P_time);
  digitalWrite(Print3, HIGH);
  
  digitalWrite(Print4, LOW);
  delay(P_time);
  digitalWrite(Print4, HIGH);
  
  digitalWrite(Print5, LOW);
  delay(P_time);
  digitalWrite(Print5, HIGH);
  
  newLN();
  
}
