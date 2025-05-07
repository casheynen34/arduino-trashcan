#include <LiquidCrystal.h>

// Initialize LCD with correct pins (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(6, 8, 2, 3, 4, 5);

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 7;  // LED output

bool objectDetected = false;
unsigned long detectionTime = 0;
int counter = 0;  // Counter for detection events
bool previousState = false; // Stores previous detection state

const int resetPin = 12;  // Reset button

void setup() {
    pinMode(resetPin, INPUT_PULLUP);  // Set reset button as input with internal pull-up

    Serial.begin(9600);
    
    // Initialize LCD
    lcd.begin(16, 2);  // 16x2 LCD
    lcd.setCursor(0, 0);
    lcd.print("Counter: 0");

    lcd.setCursor(0, 1);  // Second row
    lcd.print("Out of 20");

    // Initialize sensor and LED pins
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Send a pulse to trigger the sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read echo pulse duration
    long duration = pulseIn(echoPin, HIGH);

    // Convert duration to distance in centimeters
    float distance = duration * 0.034 / 2;

    if (counter >= 20) {
    counter = 0;  // Reset when reaching a certain number
    }

    if (digitalRead(resetPin) == LOW) {  // Button is pressed (LOW because of pull-up resistor)
        counter = 0;  // Reset counter
        Serial.println("Counter Reset!");

        lcd.setCursor(9, 0);
        lcd.print("      ");  // Clear previous number
        lcd.setCursor(9, 0);
        lcd.print(counter);
    }

    // Check if distance is less than 10 cm
    if (distance < 10) {
        objectDetected = true;
        detectionTime = millis();
        digitalWrite(ledPin, HIGH);  // Turn on LED
    }

    // Turn boolean off after 2 seconds and turn off LED
    if (objectDetected && millis() - detectionTime >= 100) {
        objectDetected = false;
        digitalWrite(ledPin, LOW);
    }

    // Check for transition from detected (true) to not detected (false)
    if (previousState == true && objectDetected == false) {
        counter++;  // Increment counter when detection goes from 1 to 0
        Serial.print("Detection Count: ");
        Serial.println(counter);

        // Update LCD with new counter value
        lcd.setCursor(9, 0);  
        lcd.print("      "); // Clear previous number
        lcd.setCursor(9, 0);
        lcd.print(counter);
    }

    // Update previous state for next check
    previousState = objectDetected;

    delay(100);  // Small delay before next measurement
}
