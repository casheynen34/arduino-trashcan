const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 7;  // Define the output pin for the LED

bool objectDetected = false;
unsigned long detectionTime = 0;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT); // Set LED pin as output
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

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Check if distance is less than 10 cm
    if (distance < 10) {
        objectDetected = true;  // Set boolean to true
        detectionTime = millis();  // Store the detection time
        digitalWrite(ledPin, HIGH);  // Turn on the LED
    }

    // Turn boolean off after 2 seconds and turn off LED
    if (objectDetected && millis() - detectionTime >= 100) {
        objectDetected = false;
        digitalWrite(ledPin, LOW);  // Turn off the LED
    }

    // Debugging output
    Serial.print("Object Detected: ");
    Serial.println(objectDetected);

    delay(100);  // Small delay before next measurement
}
