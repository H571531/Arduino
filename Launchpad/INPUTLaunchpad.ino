#include <Keypad.h>
#include <Wire.h>

const byte numRows= 4;

const byte numCols= 4;

const byte engNumRows=2;
const byte engNumCols=3;


char keymap[numRows][numCols]= { 
{'1', '2', '3', 'A'},

{'4', '5', '6', 'B'},

{'7', '8', '9', 'C'},

{'*', '0', '#', 'D'} };

char engKeymap[2][3]={
  {'3', '6', '9'},
  {'5', '4', 'n'}};


byte rowPins[numRows] = {9, 8, 7, 6}; 
byte colPins[numCols] = {5, 4, 3, 2}; 

byte engRowPins[2]={0,13};
byte engColPins[3]={12,11,10};

//initializes two instances of the Keypad class
Keypad myKeypad=Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
Keypad EngIn=Keypad(makeKeymap(engKeymap),engRowPins,engColPins,2,3);

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
}


void loop() {
/*//DEBUG
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








