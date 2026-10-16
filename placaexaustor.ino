// constants won't change
const int RELAY_PIN1 = 3;
const int RELAY_PIN2 = 4;
const int RELAY_PIN3 = 5;
const int RELAY_PIN4 = 6;
const int ONOFF = 7;
const int MORE = 8;
const int LESS = 9;
const int LIGHTONOFF = 10;

int onoffstate = 0;
int lightstate = 0;
int morestate  = 0;
int lessstate  = 0;
int power      = 0;

void setup() {
  pinMode(RELAY_PIN1, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);
  pinMode(RELAY_PIN3, OUTPUT);
  pinMode(RELAY_PIN4, OUTPUT);
  pinMode(ONOFF, INPUT_PULLUP);
  pinMode(MORE, INPUT_PULLUP);
  pinMode(LESS, INPUT_PULLUP);
  pinMode(LIGHTONOFF, INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(RELAY_PIN1, HIGH);
  digitalWrite(RELAY_PIN2, HIGH);
  digitalWrite(RELAY_PIN3, HIGH);
  digitalWrite(RELAY_PIN4, HIGH);
}

void turnoff() {
  digitalWrite(RELAY_PIN1, HIGH);   //we make sure all the relays that control the other speeds are down
  digitalWrite(RELAY_PIN2, HIGH);
  digitalWrite(RELAY_PIN3, HIGH);
//  delay(300);
}

void powerdecider() {
  if (power == 1) {
    digitalWrite(RELAY_PIN2, HIGH);
    digitalWrite(RELAY_PIN3, HIGH);
    delay(300); //we have just switched on all the relays but we wait a while before starting to give current to another coil of the motor to make sure the other coils have no current. We wait 300ms instead of the 5µs Arduino would need to perform the function.
    digitalWrite(RELAY_PIN1, LOW); //we finally switch on or off the relay that controls the slow speed 1
  }
  if (power == 2) {
    digitalWrite(RELAY_PIN1, HIGH);   //we make sure all the relays that control the other speeds are down
    digitalWrite(RELAY_PIN3, HIGH);
    delay(300);
    digitalWrite(RELAY_PIN2, LOW); //we switch on or off the relay that controls the medium speed 2
  }
  if (power == 3) {
    digitalWrite(RELAY_PIN1, HIGH);   //we make sure all the relays that control the other speeds are down
    digitalWrite(RELAY_PIN2, HIGH);
    delay(300);
    digitalWrite(RELAY_PIN3, LOW); //we switch on or off the relay that controls the high speed 3
  }
  if (power == 0) {
    turnoff();
  }
}

void powerswitches() {
  if (digitalRead(ONOFF) == HIGH) {
    onoffstate = 0;
  }
  if (digitalRead(ONOFF) == LOW) {
    onoffstate = 1;
  }
  if (digitalRead(MORE) == HIGH) {
    morestate = 0;
  }
  if (digitalRead(MORE) == LOW) {
    morestate = 1;
  }
  if (digitalRead(LESS) == HIGH) {
    lessstate = 0;
  }
  if (digitalRead(LESS) == LOW) {
    lessstate = 1;
  }
  power = onoffstate + morestate + lessstate;
  Serial.print(power);
}

void lightswitch() {
  digitalWrite(RELAY_PIN4, digitalRead(LIGHTONOFF));
}

void loop() {
  powerdecider();
  powerswitches();
  lightswitch();
}
