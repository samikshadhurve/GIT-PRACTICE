// #include <Servo.h>
// #include <SoftwareSerial.h>
// #include <Wire.h>
// #include <Adafruit_BNO055.h>


// Servo myServo;
// const int buttonPin = 6;
// const int servoPin = 9;
// int buttonState = 0;
// int lastButtonState = 0;
// int servoPosition = 0;


// #define RXPin 4
// #define TXPin 5
// #define GPSBaud 9600
// SoftwareSerial gpsSerial(RXPin, TXPin);
// String latitude = "";
// String longitude = "";

// Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28); // Default I2C address

// void setup() {

//   myServo.attach(servoPin);
//   pinMode(buttonPin, INPUT_PULLUP);
//   myServo.write(servoPosition);

//   Serial.begin(115200);
//   gpsSerial.begin(GPSBaud);


//   Serial.println("BNO055 Test");
//   if (!bno.begin()) {
//     Serial.println("Error: BNO055 not detected. Check connections and address.");
//     while (1); // Halt program
//   }

//   bno.setExtCrystalUse(true);
// }

// void loop() {
//    buttonState = digitalRead(buttonPin);
//   if (buttonState == LOW && lastButtonState == HIGH) {
//     servoPosition += 30;
//      Serial.println("1");
//     if (servoPosition >=180) {
//       servoPosition = 0;
//            Serial.println("2");
//     }
//     myServo.write(servoPosition);
//     delay(200);
//   }
//   lastButtonState = buttonState;


//   // GPS Functionality
//   while (gpsSerial.available() > 0) {
//     String sentence = gpsSerial.readStringUntil('\n'); // Read an NMEA sentence
//     if (sentence.startsWith("$GNGLL")) {
//       parseGNGLL(sentence);
//     }
//   }

//   // BNO055 Functionality
//   sensors_event_t event;
//   bno.getEvent(&event); // Fetch Euler angles
//   Serial.print("Angle (Heading): ");
//   Serial.print(event.orientation.x);
//   Serial.print(", Elevation (Roll): ");
//   Serial.print(event.orientation.y);
//   Serial.print(", Pitch: ");
//   Serial.println(event.orientation.z);
// }

// // Parse NMEA GNGLL sentences
// void parseGNGLL(String sentence) {
//   int index1 = sentence.indexOf(',');
//   int index2 = sentence.indexOf(',', index1 + 1);
//   int index3 = sentence.indexOf(',', index2 + 1);
//   int index4 = sentence.indexOf(',', index3 + 1);

//   if (index1 == -1 || index2 == -1 || index3 == -1 || index4 == -1) {
//     Serial.println("Error parsing sentence.");
//     return;
//   }

//   latitude = sentence.substring(index1 + 1, index2);
//   longitude = sentence.substring(index3 + 1, index4);

//   if (latitude == "" || longitude == "") {
//     Serial.println("No GPS data available.");
//     return;
//   }

//   float lat = convertToDecimalDegrees(latitude);
//   float lon = convertToDecimalDegrees(longitude);

//   Serial.print("Latitude: ");
//   Serial.print(lat, 6);
//   Serial.print(", Longitude: ");
//   Serial.println(lon, 6);
// }

// // Convert GPS coordinates to decimal degrees
// float convertToDecimalDegrees(String coord) {
//   if (coord.length() < 4) return 0; // Handle invalid input
//   float degrees = coord.substring(0, coord.indexOf('.') - 2).toFloat();
//   float minutes = coord.substring(coord.indexOf('.') - 2).toFloat();
//   return degrees + (minutes / 60.0);
// }


// ------------------------

#include <Servo.h>

Servo myServo;            // Create a Servo object
const int servoPin = 9;    // Pin for the servo motor
int servoPosition = 0;     // Current servo position
const int increment = 30;  // Servo movement increment in degrees
// const int delayTime = 1000; // Delay time between servo movements (in milliseconds)

void setup() {
  // myServo.attach(servoPin);         // Attach the servo to its pin
  // myServo.write(servoPosition);     // Initialize servo position to 0
  Serial.begin(115200);             // Initialize serial communication
  // delay(10000);                     // Wait for 10 seconds before starting
}


void loop() {
  // Simulated realistic GPS data with 6 decimal places
  Serial.println("Longitude:67.123456,Latitude:90.654321");
  delay(1000);

  Serial.println("Longitude:67.123789,Latitude:90.654987");
  delay(1000);

  Serial.println("Longitude:67.124123,Latitude:90.655123");
  delay(1000);

  Serial.println("Longitude:67.124456,Latitude:90.655456");
  delay(1000);

  Serial.println("Longitude:67.124789,Latitude:90.655789");
  delay(1000);

  Serial.println("Longitude:67.125123,Latitude:90.656123");
  delay(1000);
}
