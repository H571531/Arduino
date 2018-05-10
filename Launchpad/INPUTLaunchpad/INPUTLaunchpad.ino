/***********************
 * Sketch by Adrian M. *
 *                     *
 * http://morclan.net/ *
 *                     *
 ************************/


#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

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


byte rowPins[4] ={45,46,47,48};//{49,50,51,52};//{52, 51, 50, 49}; 
byte colPins[4] = {49,50,51,52};//{48, 47, 46, 45}; 
byte engRowPins[2]={30,31};
byte engColPins[3]={32,34,33};
byte DirPin[2]={A0,A1};
byte DirCol[2]={A2,A3};



//initializes three instances of the Keypad class
Keypad myKeypad=Keypad(makeKeymap(keymap), rowPins, colPins, 4, 4);
Keypad EngIn=Keypad(makeKeymap(engKeymap),engRowPins,engColPins,2,3);
Keypad DirPad=Keypad(makeKeymap(engDirectional),DirPin,DirCol,2,2);


void setup() { 
  lcd.begin(16, 2);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
  Wire.begin(8);
  
  // Print a message to the LCD.
  lcd.print("hello, world!");
  
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








