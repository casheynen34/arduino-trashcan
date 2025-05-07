const int trigPin = 9;
const int echoPin = 10;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    // Send a 10µs pulse to trigger the sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read echo pulse duration with an increased timeout
    long duration = pulseIn(echoPin, HIGH)

    // Convert duration to distance in centimeters
    float distance = duration * 0.034 / 2;

    // Print distance measurement
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(100);
}
