/* The doors
 The doors are waiting for the batton
 When batton is pushed - the doors go to open, 
 still open for 10 sec and then go back
 The button's LED allways ON - doors are redy to work
 When the doors are working - LED is OFF
 --------------
 LED13 на борту отражает работу посветки кнопки
 
 Long Beach CA
 06/25/2018
*/

#include <Servo.h>
Servo myservo;  // create servo object to control a servo

int pos = 93;    // variable to store the servo position
int pause = 10000; // Time that the doors still open
const int buttonPin = 4;     // the number of the pushbutton pin
const int led13 = 13;
int buttonState = 0;    // batton's state
int relay5 = 5;      // button's LED
int servo = 0;




void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(relay5, OUTPUT);
  pinMode(led13, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(90);

}

void loop() {
 // servo = myservo.read();
  // This is Setting Up for dors ----------------------------------------------------------
  // Gos once.
  if (servo == 0) {
        for (pos = 90; pos >= 22; pos -= 1) { // goes from 90 degrees to 22 degrees position
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(50);                       // waits 50ms for the servo to reach the position
      }
    delay(100);                      // Taking the pause - the doors are still open
      for (pos = 22; pos <= 90; pos += 1) { // goes from 22 degrees to 90 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(50);                       // waits 50ms for the servo to reach the position
      } 
    servo = 1;
    }
  //--------------------------------------------------------------------------------------
  
  digitalWrite(relay5, LOW);       // Switch the button's LED ON - redy to work
  digitalWrite(led13, HIGH);
  buttonState = digitalRead(buttonPin);  // Reading the battom 
  if (buttonState == HIGH) {
    digitalWrite(relay5, HIGH);       // Switch the button's LED OFF - the doors are working
    digitalWrite(led13, LOW);
    for (pos = 90; pos >= 22; pos -= 1) { // goes from 90 degrees to 22 degrees position
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(50);                       // waits 50ms for the servo to reach the position
    }
    delay(pause);                      // Taking the pause - the doors are still open
    for (pos = 22; pos <= 90; pos += 1) { // goes from 22 degrees to 90 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(50);                       // waits 50ms for the servo to reach the position
    } 
    
  }
//    
}

