#define MOISTURE_MIN 845
#define MOISTURE_MAX 388
#define MOISTURE_TRESHOLD_PERCENT 70

#define MOISTURE_SENSOR_INPUT A0
#define PUMP_OUTPUT 2

void setup() {
  // put your setup code here, to run once:
  pinMode(PUMP_OUTPUT, OUTPUT);
  togglePump(false);
  
  Serial.begin(9600);
}

void loop() {
  int moisturePercent = getMoisture();
  Serial.println(moisturePercent);

  if (moisturePercent <= MOISTURE_TRESHOLD_PERCENT) {
    togglePump(true);
  } else {
    togglePump(false);
  }

  delay(1000);
}


/*
 * HELPER FUNCTIONS 
 */

int getMoisture() {
  int moisture = analogRead(MOISTURE_SENSOR_INPUT);
  return map(moisture, MOISTURE_MIN, MOISTURE_MAX, 0, 100);
}

void togglePump(boolean start) {
  digitalWrite(PUMP_OUTPUT, start ? LOW : HIGH);
}
