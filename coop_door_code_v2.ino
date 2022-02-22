/*H**********************************************************************
* FILENAME :        coop_door_code.ino           
*
* DESCRIPTION :
*       Arduino code for chicken coop door
*
*
* NOTES :
*       Download ds3231 lib here:
*         https://github.com/rodan/ds3231
*
* AUTHOR :    MAEGHT Loan        START DATE :    26 Jul 20
*
*
*H*/

#include <Wire.h>
#include <ds3231.h>

// motor 
//speed pin out
int enA = 10;
//direction pin out
int in1 = 9;
int in2 = 8;

// set speed to 200 out of possible range 0~255
int speedd = 100;
// duration the motor run, depend on the height of the door
int timee = 4000; 

// light sensor pin
const int LDR = A0; 

// door position 0 close 1 open
int door_satus = 0;

// winter time
int winter_time =0;

// light sensor value
int input_val;


struct ts t; 
void setup()
{
  Wire.begin();
  // start comunication to clock
  DS3231_init(DS3231_CONTROL_INTCN);
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // start comunication to PC
  Serial.begin(9600);

}
void openn()
{
  // this function will run the motors at a fixed speed
  // turn on in the good direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // apply speed
  analogWrite(enA, speedd);
  // waiting for the motor to turn
  delay(timee);



  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  


}
void closee()
{
  // this function will run the motors at a fixed speed
  // turn on in the good direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // apply speed with reduction because de motor goes faster on descend
  analogWrite(enA, speedd-30);
  // waiting for the motor to turn
  delay(timee);



  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
 


}
void loop()
{
  DS3231_get(&t);// read clock
  input_val = analogRead(LDR);// read light sensor
  //show in console the current status
  Serial.print(door_satus);
  Serial.print("  /  ");
  Serial.print(t.hour);
  Serial.print("  /  ");
  Serial.println(input_val);

  

  // check if not winter time periode
  if (t.mon > 4 && t.mon <= 10){
    winter_time = 1;
  }else{
   // else we are in winter time
    winter_time = 0;
  }

  // check for end of winter time
  if (t.mon == 4 && t.mday >= 15){
    winter_time = 1;
  }
  
  if (door_satus == 0) // if door is close
  {
    if ( input_val > 20){ // if there is some light
      if (t.hour >= 9 + winter_time){ //if it is past 9 o'clock
 
        if (t.hour < 20 + winter_time){ // if it is before 20 o'clock
      openn(); // then open the door
      digitalWrite(LED_BUILTIN, HIGH); //set the arduino led to ON for debuging
      door_satus = 1;}} // save that the door is open
      
    }
  }
  else{
    if ( input_val < 5){ // if it is dark
      closee(); // close the door
      digitalWrite(LED_BUILTIN, LOW); // turn of the LED indicator
      door_satus = 0;// save door position as close
      
    }
  }
  
  
  // wait before looping again, every seconde
  delay(1000);
  
}
