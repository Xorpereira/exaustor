
void loop() {
  if (digitalRead(2) == HIGH);
  Serial.println("Sensor is touched");
  delay(500);

}

// constants won't change
const int RELAY_PIN1 = 3;  // the Arduino pin, which connects to the IN pin of relay
const int RELAY_PIN2 = 4;
const int RELAY_PIN3 = 5;
const int RELAY_PIN4 = 6;
const int ONOFF = 7;
const int MORE = 8;
const int LESS = 9;
const int LIGHTONOFF =10;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 9 as an output.
  pinMode(RELAY_PIN1, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);
  pinMode(RELAY_PIN3, OUTPUT);
  pinMode(RELAY_PIN4, OUTPUT);
  pinMode(ONOFF, INPUT);
  pinMode(MORE, INPUT);
  pinMode(LESS, INPUT);
  pinMode(LIGHTONOFF, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RELAY_PIN, HIGH);
  delay(500);
  digitalWrite(RELAY_PIN, LOW);
  delay(500);
}

