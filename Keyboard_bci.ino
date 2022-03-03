#include <Brain.h>
#include "Keyboard.h"
 
int meditation;
int meditation_t;
int attention;


 
 

Brain brain(Serial1);

 
void setup()
   {
    // Start the hardware serial.
 Serial.begin(9600);
 Serial1.begin(9600); // Leonardo’s TX/RX pins     
 Keyboard.begin();

   }
 
 
void loop()
   {
    // Expect pac kets about once per second.
    // The .readCSV() function returns a string (well, char*) listing the most recent brain data, in the following format:
    // "signal strength, attention, meditation, delta, theta, low alpha, high alpha, low beta, high beta, low gamma, high gamma"    
    if (brain.update())
       {
        //Serial.println(brain.readErrors());
               
        Serial.println(brain.readCSV());
        
        meditation = brain.readMeditation();
        
        
        Serial.print("Meditation = ");
        Serial.println(meditation);
        
        /*
        Serial.print(brain.readSignalQuality());
        Serial.print("   ");
        Serial.print(brain.readDelta());   
        Serial.print("   ");
        Serial.print(brain.readTheta());
        Serial.print("   ");
        Serial.print(brain.readLowAlpha());
        Serial.print("   ");
        Serial.print(brain.readLowBeta());
        Serial.print("   ");
        Serial.println(brain.readHighBeta());
        */    
        
        
        
        meditation_t = map(meditation,0,100,0,90);

        
        if ((meditation_t >= 1) && (meditation_t < 20 ))
           {
            Keyboard.press(73);
            delay(100);
            Keyboard.release(73);
           }
           
           
           if ((meditation_t >= 75) && (meditation_t < 100))
           {
            Keyboard.press(72);
            delay(100);
            Keyboard.release(72);
           }
         
                   
       }
   }
