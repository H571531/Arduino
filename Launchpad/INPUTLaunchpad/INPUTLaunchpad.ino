/***********************
 * Sketch by Adrian M. *
 *                     *
 * http://morclan.net/ *
 *                     *
 ************************/
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>



const byte numCols= 4;


const byte engNumRows=2;
const byte engNumCols=3;


//-----Setup for keymap----- Default keymap (Numpad)

char keymap[4][4]= { 
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}};
/*
char engKeymap[2][3]={
{'3', '6', '9'},
{'5', '4', 'n'}};*/

/*char engDirectional[2][2]={
{'u','l'},
{'r','d'}};*/

//--------Constants---------

//LCD
// creating variables for each LCD interface pin with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

//Inputs
const byte rowPins[4] ={45,46,47,48};//{49,50,51,52};//{52, 51, 50, 49}; 
const byte colPins[4] = {49,50,51,52};//{48, 47, 46, 45}; 
const byte engRowPins[2]={30,31};
const byte engColPins[3]={32,34,33};
const byte DirPin[2]={A0,A1};
const byte DirCol[2]={A2,A3};

//Global variables
char input=' ';
String profile="";

//initializes an instance of the Keypad class
Keypad myKeypad=Keypad(makeKeymap(keymap), rowPins, colPins, 4, 4);
/*
Keypad EngIn=Keypad(makeKeymap(engKeymap),engRowPins,engColPins,2,3);
Keypad DirPad=Keypad(makeKeymap(engDirectional),DirPin,DirCol,2,2);
*/

// initialize the library by associating any needed LCD interface pin
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



//First bit of code that will run
void setup() { 
  lcd.begin(16, 2);//Start the lcd
  
  Serial.begin(9600);
  
  
  // Print a message to the LCD.
  lcd.print("Booting...");
  lcd.setCursor(0, 1);
  //Small loop for holding back l2c For easy flash/reflash. 
  //(My board sometimes gets buggy with the flash if l2c is already running while I try and make changes, This also creates a cool "Boot" effect.) 
  for(int i=0;i<16;i++){
    lcd.print("0");
    delay(100);
  }
  Wire.begin(8);//Start the wire
  bootSeq(); //Start the profile selector
  Wire.onRequest(requestEvent); //Actually start recieving requests
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

}


//-------Sequence for changing what profile and keymap I want to run -----
void bootSeq(){
  lcd.clear();
  lcd.print("Select profile:");
  lcd.setCursor(0, 1);
   
  //Do while loop to read keypad inputs
  do{
     char input=myKeypad.getKey(); //Get the current input char
    if(input!=NO_KEY){
      if(input!='#'){
    lcd.print(input);
    profile=profile+input;//Add the input char to profile String
      }/*else{
        break; //Dead code
      }*/
    }
    }while(input!='#'); //Use '#' as Enter
    lcd.clear();
    lcd.print(profile);
    lcd.setCursor(0, 1);
    if(profile.equals("A001")){
      lcd.print(" Star Citizen");
      loadSC();
    }else if(profile.equals("B001")){
      lcd.print("Elite: Dangerous");
      loadED();
    }else if(profile.equals("D200")){
      lcd.print("M2000 Baguette");
      loadDCSM2000();
    }else if(profile.equals("D010")){
      lcd.print("A10 Warthog");
      loadDCSA10();
    }
    
}

void loadSC(){ //ID: A001
 /* char keymap[4][4]= { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}};*/

  char engKeymap[2][3]={
  {'3', '6', '9'},
  {'5', '4', 'n'}};

  char engDirectional[2][2]={
  {'u','l'},
  {'r','d'}};

  Keypad EngIn=Keypad(makeKeymap(engKeymap),engRowPins,engColPins,2,3);
  Keypad DirPad=Keypad(makeKeymap(engDirectional),DirPin,DirCol,2,2);
}

void loadED(){//ID: B001
 /* char keymap[4][4]= { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}};*/

  char engKeymap[2][3]={
  {'3', '6', '9'},
  {'5', '4', 'n'}};

  char engDirectional[2][2]={
  {'u','l'},
  {'r','d'}};

  Keypad EngIn=Keypad(makeKeymap(engKeymap),engRowPins,engColPins,2,3);
  Keypad DirPad=Keypad(makeKeymap(engDirectional),DirPin,DirCol,2,2);
}

void loadDCSM2000(){//ID: D200
  /*char keymap[4][4]= { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}};*/

  char engKeymap[2][3]={
  {'3', '6', '9'},
  {'5', '4', 'n'}};

  char engDirectional[2][2]={
  {'u','l'},
  {'r','d'}};
  
  Keypad EngIn=Keypad(makeKeymap(engKeymap),engRowPins,engColPins,2,3);
  Keypad DirPad=Keypad(makeKeymap(engDirectional),DirPin,DirCol,2,2);

}

void loadDCSA10(){//Id: D010
 /* char keymap[4][4]= { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}};*/

char engKeymap[2][3]={
  {'3', '6', '9'},
  {'5', '4', 'n'}};

char engDirectional[2][2]={
  {'u','l'},
  {'r','d'}};
  Keypad EngIn=Keypad(makeKeymap(engKeymap),engRowPins,engColPins,2,3);
  Keypad DirPad=Keypad(makeKeymap(engDirectional),DirPin,DirCol,2,2);
}



