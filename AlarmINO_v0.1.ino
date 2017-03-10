
/* AllarmINO - Security System GSM
  Author: Fabb2303
  Version: 0.1 Alpha
*/

int ledgreen = 13;                // Define the LED Green as Pin 13
int ledred = 12; // Define the LED Red as Pin 13
int sensor = 4;              // Define the PIR to Pin 4
int state = LOW;             // Set Motion
int val = 0;                 // Sensor Value

void setup() {
  pinMode(ledgreen, OUTPUT);      // initialize the LED Green as the output
  pinMode(ledred, OUTPUT);  // initialize the LED Red as the output
  pinMode(sensor, INPUT);    // initialize the sensor as the input
}

void loop() {
  val = digitalRead(sensor);   // Reading the sensor value
  if (val == HIGH) {           
    
    // if sensor is high --> motion detected
    digitalWrite(ledred, HIGH);   // switch on the LED RED (RED = motion detected)
    digitalWrite(ledgreen, LOW); // switch off the LED Green (GREEN = no motion detected)
    delay(100);                // 100 milliseconds delay

    if (state == LOW) {
      state = HIGH;       // Update the variable state in to HIGH
    }
  }
  else { 
    
    // if sensor is LOW --> no motion detected
    digitalWrite(ledred, LOW); // switch off the LED RED (RED = motion detected)
    digitalWrite(ledgreen, HIGH); // switch on the LED Green (GREEN = no motion detected)
    delay(200);             // 200 milliseconds delay

    if (state == HIGH) {
      state = LOW;       // update the variable state into LOW
    }
  }
}
