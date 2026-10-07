/* Smart Parking System
   Ultrasonic Sensor -> Arduino Uno -> Decision -> LEDs + Buzzer */

const int trigPin  = 9;    // ultrasonic TRIG
const int echoPin  = 10;   // ultrasonic ECHO
const int greenLed = 4;    // available
const int redLed   = 5;    // occupied
const int buzzer   = 6;    // alert

const int thresholdCm = 30;   // occupied if distance <= 30 cm

long duration;      // echo time in microseconds
float distanceCm;   // calculated distance

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  /* 1. Send a 10 microsecond trigger pulse */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  /* 2. Measure how long the echo pin stays HIGH */
  duration = pulseIn(echoPin, HIGH, 30000);   // 30 ms timeout

  /* 3. Convert time to distance (speed of sound = 0.0343 cm/us).
        Divide by 2 because the sound travels there AND back. */
  distanceCm = duration * 0.0343 / 2;

  /* 4. Decide: occupied or available */
  if (duration > 0 && distanceCm <= thresholdCm)
  {
    // OCCUPIED
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000);            // 1 kHz alert
    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm -> OCCUPIED");
  }
  else
  {
    // AVAILABLE
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    noTone(buzzer);                // buzzer off
    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm -> AVAILABLE");
  }

  delay(200);   // short pause between readings
}