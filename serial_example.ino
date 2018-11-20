// Stepper - Version: Latest 
#include <Stepper.h>

int incomingByte = 0;   // for incoming serial data
unsigned long previousMicros = 0; //will store the previous update time
unsigned long interval = 0; //will store the time interval to wait
unsigned long receiveTime = 0;
void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {
  
        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                receiveTime = millis();
                
                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte, DEC);
                unsigned long interval = 10000;
                boolean flag = 0;
                if (receiveTime - previousMicros >= interval) {
                  // save the last time you blinked the LED
                  // previousMicros = receiveTime;
                  flag = 1;  //set the flag if its past the interval
                  
                  //do the other stuff (eg. blink an led)
                }
                
                Serial.println(flag);
        }
        

}