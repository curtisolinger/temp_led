// This will be the pin that drives the LED (using PWM).
const int ledPin = 3;
// This will be the analog pin that reads the voltage values from the tmp sensor.
const int sensorPin = A0;

void setup() {
  // Set the pin to which the LED is attached to OUTPUT.
  pinMode(ledPin, OUTPUT);
  // Set the voltage to zero and thus make sure the LED is off for good measure. 
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Read the voltage value coming from the TMP sensor, convert that to 0 to 1023,
  // and store that value in sensorVal
  int sensorVal = analogRead(sensorPin);

  // map the sensorVal (between 0 and 1023) to a value x \in [0, 255] where x
  // cooresponds to the duty cycle for the LED, i.e. the percent of time during
  // a period which the LED is set to HIGH.
  sensorVal = map(sensorVal, 0, 1023, 0, 255);

  // Turn on the LED, attached to ledPin, with a duty cycle of sensorVal.
  analogWrite(ledPin, sensorVal);

  // Delay this loop so the analogRead function can catch up.
  delay(1);
}
