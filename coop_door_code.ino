/*H**********************************************************************
* FILENAME :        coop_door_code.ino           
*
* DESCRIPTION :
*       Arduino code for chicken coop door
*       Open and close at set time
*
* NOTES :
*       Download ds3231 lib here:
*         https://github.com/rodan/ds3231
*
* AUTHOR :    MAEGHT Loan        START DATE :    26 Jul 20
*
*
*H*/
// import
#include <Wire.h>
#include <ds3231.h>

// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// set speed to 200 out of possible range 0~255
int speedd = 100;
// duration the motor run, depend on the height of the door
int timee = 3500; 

// light sensor pin
const int LDR = A0; 

// door position 0 close 1 open
int door_satus = 0;

// winter time
int spring_time =0;

// light sensor value
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
  // this function will run the motors at a fixed speed
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // apply speed
  analogWrite(enA, speedd);
  // waiting set time (4s)
  delay(timee);



  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  


}
void closee()
{
  // this function will run the motors s at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // apply speed with reduction because de motor goes faster on descend
  analogWrite(enA, speedd-30);
  // waiting set time (4s)
  delay(timee*0.75);



  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  pinMode(LED_BUILTIN, OUTPUT); 


}
void loop()
{

  
  
  
  DS3231_get(&t);// read clock
  input_val = analogRead(LDR);// read light sensor
  
  // manage spring time
  if (t.mon >= 4 && t.mon <= 10){
    spring_time = 1;
  }else{
    spring_time = 0;
  }

//Débug
  Serial.print(door_satus);
  Serial.print("  /  ");
  Serial.print(t.hour+spring_time);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print("  /  ");
  Serial.print(spring_time);
  Serial.print("  /  ");
  Serial.print(t.mday);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("  /  ");
  Serial.println(input_val);


  
  
  
  if (door_satus == 0) // if door is close
  {
    if ( input_val > 20){ // if there is some light
      if (t.hour + spring_time >= 9 ){ //if it is past 9 o'clock
 
        if (t.hour + spring_time < 20 + (spring_time*2)){ // if it is before 20 o'clock or 23 in winter
      openn(); // then open the door
      digitalWrite(LED_BUILTIN, HIGH); //set the arduino led to ON for debuging
      door_satus = 1;}} // save that the door is open
      
    }
  }
  else{
    if ( input_val < 10 || t.hour + spring_time >= 22 ){ // if it is dark or past 22
      closee(); // close the door
      digitalWrite(LED_BUILTIN, LOW); // turn of the LED indicator
      door_satus = 0;// save door position as close
      
    }
  }
  
  
  
  delay(1000);
  
}
