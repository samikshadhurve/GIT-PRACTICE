#include "color_sensor.h"

color_sensor::color_sensor() {
    pinMode(s0, OUTPUT); // Set pin modes
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);
    pinMode(out, INPUT);

  }

// Function to get the red color value
void color_sensor::get_redvalue() {
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    Serial.print("Red value= ");
    get_data();
}

// Function to get the blue color value
void color_sensor::get_bluevalue() {
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    Serial.print("Blue value= ");
    get_data();
}

// Function to get the green color value
void color_sensor::get_greenvalue() {
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    Serial.print("Green value= ");
    get_data();
}

// Function to get data from the sensor
void color_sensor::get_data() {
    data = pulseIn(out, LOW);  
    Serial.print(data);
    Serial.print("  "); 
    delay(20);
}

// Function to set frequency scaling to 20%
void color_sensor::get_20_frequency() {
    digitalWrite(s0, LOW);
    digitalWrite(s1, HIGH);
}

// Function to set frequency scaling to 2%
void color_sensor::get_2_frequency() {
    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);
}
