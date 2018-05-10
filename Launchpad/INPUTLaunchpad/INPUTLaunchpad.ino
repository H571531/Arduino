/***********************
 * Sketch by Adrian M. *
 *                     *
 * http://morclan.net/ *
 *                     *
 ************************/


#include <Keypad.h>
#include <Wire.h>


char keymap[4][4]= { 
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}};

char engKeymap[2][3]={
{'3', '6', '9'},
{'5', '4', 'n'}};

char engDirectional[2][2]={
{'u','l'},
{'r','d'}};


byte rowPins[4] = {9, 8, 7, 6}; 
byte colPins[4] = {5, 4, 3, 2}; 
byte engRowPins[2]={0,13};
byte engColPins[3]={12,11,10};

byte DirPin[2]={A0,A1};
byte DirCol[2]={A2,A3};



//initializes three instances of the Keypad class
Keypad myKeypad=Keypad(makeKeymap(keymap), rowPins, colPins, 4, 4);
Keypad EngIn=Keypad(makeKeymap(engKeymap),engRowPins,engColPins,2,3);
Keypad DirPad=Keypad(makeKeymap(engDirectional),DirPin,DirCol,2,2);


void setup() {
  Serial.begin(9600);
  Wire.begin(8);
  Wire.onRequest(requestEvent);
}

//If key is pressed, this key is stored in a 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is sent out through Wire
void requestEvent(){
 char ReturnEng=EngIn.getKey();
  if(ReturnEng!=NO_KEY){
    Wire.write(ReturnEng);
  }
  
  char ReturnPad=myKeypad.getKey();
  if(ReturnPad!=NO_KEY){
    Wire.write(ReturnPad);
  }

  char ReturnDir=DirPad.getKey();
  if(ReturnDir!=NO_KEY){
    Wire.write(ReturnDir);
  }
}


void loop() {
/*
 //DEBUG
 char ReturnEng=EngIn.getKey();
 // Serial.write("Er hoy");
if(ReturnEng!=NO_KEY){
    Serial.write(ReturnEng);
  }
  char ReturnPad=myKeypad.getKey();
  if(ReturnPad!=NO_KEY){
    Serial.write(ReturnPad);
  }
  */
}








