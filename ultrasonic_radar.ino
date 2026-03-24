const int trigPin = 5;   
const int echoPin = 18;  
const int ledPin = 13;   

void setup() {
  // Configure pins
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(ledPin, OUTPUT);  
  
  // Initialize serial communication for debugging
  Serial.begin(115200); 
}

void loop() {
  // 1. Trigger the ultrasonic sensor to send a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // 2. Read the echo and calculate distance
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // 3. Adaptive LED blink rate logic based on proximity
  if (distance >= 80 && distance <= 100) {
    // Target is far: slow blink (2Hz)
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  } 
  else if (distance >= 50 && distance < 80) {
    // Target is getting closer: medium blink (4Hz)
    digitalWrite(ledPin, HIGH);
    delay(125);
    digitalWrite(ledPin, LOW);
    delay(125);
  } 
  else if (distance >= 20 && distance < 50) {
    // Target is close: fast blink (8Hz)
    digitalWrite(ledPin, HIGH);
    delay(62);
    digitalWrite(ledPin, LOW);
    delay(62);
  } 
  else if (distance > 0 && distance < 20) {
    // Target is extremely close (< 20cm): solid light (Danger)
    digitalWrite(ledPin, HIGH);
    delay(50); 
  } 
  else {
    // No target detected (or out of range): turn off LED
    digitalWrite(ledPin, LOW);
    delay(50); 
  }
}
