#include "color_sensor.h"

// Create an instance of the color_sensor class
color_sensor color;
// #define s0 10       
//  #define s1 9
//  #define s2 13
//  #define s3 11
//  #define out 8
void setup() {
   
    Serial.begin(9600); // Initialize the serial monitor baud rate

    color.get_2_frequency(); // Set frequency scaling to 20%
}

void loop() {
    color.get_redvalue();   // Get red value
    color.get_bluevalue();  // Get blue value
    color.get_greenvalue(); // Get green value
    Serial.println();

    delay(1000);
}
