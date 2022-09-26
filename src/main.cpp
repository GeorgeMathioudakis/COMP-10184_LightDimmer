/// I, George Mathioudakis,  001211882, certify that this material is my original work. No other person's work has been used without due acknowledgment and I have not made my work available to anyone else.
#include <Arduino.h>

bool light = false; // global ligh state

void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
 
} 
 
 
void loop() { 
  int iButton; 
  int bits;
   
  // read the push button input
  iButton = digitalRead(D5); 

// check if button was pressed
  if(iButton == 0){
    //check current state of light
    if(light){
   // turn light state off
    light = false;
      
  }
  else{
    // turn light state on
    light = true;
  }
  }

// check if light is on
  if(light == true){
    bits = analogRead(A0);
    // write to brightness of light using dial
    analogWrite(D4, bits);
  }else{
    // turning light off
    digitalWrite(D4, HIGH); 
  }
  // delay for weird button behavior 
  delay(1);
}
  
 
 
 
