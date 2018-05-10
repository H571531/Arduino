#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <Keyboard.h>


#define PIN 15
#define PIN2 14
char incomingByte; 
char c;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel circle =Adafruit_NeoPixel(12,PIN2, NEO_GRB+NEO_KHZ800); 

int toggleLights;
int toggleEngines;
int togglePower;
int toggleShield;
int toggleLandinggear;
int toggleStatus;

const int lights=1;
const int power=7;
const int engines=6;
const int shields=5;
const int landingGear=4;

//Shields display
const int RightS=3;
const int FrontS=0;
const int BackS=6;



void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  circle.begin();
  circle.show();
  
  Wire.begin();
  
  
   toggleLights=0;
   toggleEngines=0;
   togglePower=0;
   toggleShield=1;
   //toggleDoors=0;
   toggleLandinggear=0;
   toggleStatus=0;
   runPresets();
}

void loop() {
 
        // send data only when you receive data:
                    strip.setPixelColor(0,0, 0, 255);
                    strip.setBrightness(64);

                    circle.setPixelColor(0,0,0,255);
                    circle.setPixelColor(3,255,0,0);
                    circle.setPixelColor(6,0,255,0);
                    circle.setPixelColor(9,255,255,0);
                    circle.setBrightness(64);
                    circle.show();
                    

    Wire.requestFrom(8,1);
    while (Wire.available()) { // slave may send less than requested
       c = Wire.read(); // receive a byte as character
        Serial.write(c);
        if(c=='A'){ // DEBUG
                      Keyboard.begin();
                      Keyboard.print(c);
                      Keyboard.end();
                      
                      strip.setPixelColor(0, 255, 0, 255);
                      strip.setBrightness(64);
                      strip.show();//
                      delay(20);
            }else if(c=='3'){ //Lights
                      Keyboard.begin();
                      Keyboard.print(c);
                      Keyboard.end();
                      toggleLights++;
                      if(toggleLights%2==1){
                      strip.setPixelColor(1, 0, 2553333, 0);
                      }else{
                        strip.setPixelColor(1, 255, 0, 0);
                      }
                      strip.show();//
                      delay(20);
            }else if(c=='4'){//ENGINES
                      Keyboard.begin();
                      Keyboard.print(c);
                      Keyboard.end();
                      toggleEngines++;
                      if(toggleEngines%2==1){
                      strip.setPixelColor(engines, 0, 2553333, 0);
                      }else{
                        strip.setPixelColor(engines, 255, 0, 0);
                      }
                      strip.show();//
                      delay(20);
            }else if(c=='5'){//Power
                      Keyboard.begin();
                      Keyboard.print(c);
                      Keyboard.end();
                      togglePower++;
                      if(togglePower%2==1){
                      strip.setPixelColor(power, 0, 2553333, 0);
                      }else{
                        strip.setPixelColor(power, 255, 0, 0);
                      }
                      strip.show();//
                      delay(20);
            }else if(c=='6'){//SHIELD
                      Keyboard.begin();
                      Keyboard.print(c);
                      Keyboard.end();
                      toggleShield++;                      
                      if(toggleShield%2==1){
                      strip.setPixelColor(shields, 0, 2553333, 0);
                      }else{
                        strip.setPixelColor(shields, 255, 0, 0);
                      }
                     
                      strip.show();//
                      delay(20);
            }else if(c=='n'){//LANDING GEAR
                      Keyboard.begin();
                      Keyboard.print(c);
                      Keyboard.end();
                      toggleLandinggear++;
                      if(toggleLandinggear%2==1){
                      strip.setPixelColor(landingGear, 0, 255, 0);
                      }else{
                        strip.setPixelColor(landingGear, 255, 0, 0);
                      }
                      strip.show();//
                      delay(20);
            }else if(c=='9'){//OPEN CLOSE ALL EXTERIOR
                      Keyboard.begin();
                      Keyboard.print(c);
                      Keyboard.end();
                      delay(20);
            }else if(c=='D'){
              toggleStatus++;
              if(toggleStatus%2==1){
                      Serial.write("AV");
                      strip.setBrightness(0);
                      }else{
                        Serial.write("Pa");
                        strip.setBrightness(64);
                        strip.show();
                      }
                      delay(20);
            }else if(c=='d'){
              Serial.write("Avionics");
              Keyboard.begin();
              Keyboard.press(200);
              delay(20);
              Keyboard.releaseAll();
              Keyboard.end();
            }else if(c=='u'){
              Serial.write("PowerDist-Reset");
              Keyboard.begin();
              Keyboard.press(201);
              delay(20);
              Keyboard.releaseAll();
              Keyboard.end();
            }else if(c=='l'){
              Serial.write("Weapons");
              Keyboard.begin();
              Keyboard.press(198);
              delay(20);
              Keyboard.releaseAll();
              Keyboard.end();
            }else if(c=='r'){
              Serial.write("Shields");
              Keyboard.begin();
              Keyboard.press(199);
              delay(20);
              Keyboard.releaseAll();
              Keyboard.end();
            }
 
                
    }
}
                  
void runPresets(){
  strip.setPixelColor(lights, 255, 0, 0);
  strip.setPixelColor(power, 255, 0, 0);
  strip.setPixelColor(engines, 255, 0, 0);
  strip.setPixelColor(landingGear, 255, 0, 0);
  strip.setPixelColor(shields, 0, 255, 0);
  strip.show();
}
                    
  

      
    

