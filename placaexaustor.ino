// constants won't change
const int RELAY_PIN1 = 3;
const int RELAY_PIN2 = 4;
const int RELAY_PIN3 = 5;
const int RELAY_PIN4 = 6;
const int ONOFF = 7;
const int MORE = 8;
const int LESS = 9;
const int LIGHTONOFF =10;
const int onoffstate = 0;
const int strength = 1;
const int lightstate = 0;

void setup() {
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

void onofftoggle() {
	if (digitalRead(ONOFF) == HIGH) {
		if (onoffstate) == 0 {
		onoffstate = 1;
		digitalWrite(RELAY_PIN1, HIGH);
		}
	}
    else {
      onoffstate = 0;
      digitalWrite(RELAY_PIN1, LOW);
    }
}

void powerup() {
	if (digitalRead(MORE) == HIGH) {
		if (strength) < 3 {
			strength = strength+1;
			if(strength) == 2){
				digitalWrite(RELAY_PIN2, HIGH);
			}
			else if(strength) == 3 {
				digitalWrite(RELAY_PIN3, HIGH);
			}
		}
	}	
}

void powerdown() {
	if (digitalRead(MORE) == HIGH) {
		if (strength) > 1 {
			strength = strength-1;
			if(strength) == 1){
				digitalWrite(RELAY_PIN2, LOW);
			}
			else if(strength) == 2 {
				digitalWrite(RELAY_PIN3, LOW);
			}
		}
	}	
}

void togglelight() {
	if (digitalRead(LIGHTONOFF) == HIGH) {
		if (lightstate) == 0 {
		lightstate = 1;
		digitalWrite(RELAY_PIN4, HIGH);
		}
	}
    else {
      lightstate = 0;
      digitalWrite(RELAY_PIN4, LOW);
    }
}

void loop() {
	onofftoggle();
	powerup()
	powerdown()
	togglelight()
}
