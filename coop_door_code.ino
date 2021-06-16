// connect motor controller pins to Arduino digital pins
// motor one
#include <Wire.h>
#include <ds3231.h>

int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
int speedd = 100;
int timee = 4000; 
const int LDR = A0; 
int door_satus = 0;
int input_val;


struct ts t; 
void setup()
{
  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN);
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);

}
void openn()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, speedd);
 
  delay(timee);



  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  


}
void closee()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, speedd-30);
 
  delay(timee);



  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  pinMode(LED_BUILTIN, OUTPUT); 


}
void loop()
{
  DS3231_get(&t);
  input_val = analogRead(LDR);
  Serial.print(door_satus);
  Serial.print("  /  ");
  Serial.print(t.hour);
  Serial.print("  /  ");
  Serial.println(input_val);
  if (door_satus == 0)
  {
    if ( input_val > 20){
      if (t.hour >= 9){
 
        if (t.hour < 20){ //20
      openn();
      digitalWrite(LED_BUILTIN, HIGH);
      door_satus = 1;}}
      
    }
  }
  else{
    if ( input_val < 5){
      closee();
      digitalWrite(LED_BUILTIN, LOW);
      door_satus = 0;
      
    }
  }
  
  
  
  delay(1000);
  
}
