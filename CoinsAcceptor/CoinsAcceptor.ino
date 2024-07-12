#define COUNTER_PIN_NAME 2
#define ACTIVATOR_PIN_NAME 6
#define BAUDRATE_PC 57600

uint8_t pulse_cont = 0;
int t0 = 0;

void incomingImpuls() {
  t0 = millis();
  pulse_cont++;
}

void setup() {
  Serial.begin(BAUDRATE_PC);
  pinMode(COUNTER_PIN_NAME, INPUT_PULLUP);
  pinMode(ACTIVATOR_PIN_NAME, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(COUNTER_PIN_NAME), incomingImpuls, FALLING);
  digitalWrite(ACTIVATOR_PIN_NAME, HIGH);
}

void loop() {
  stateCountPulses();
}

void stateCountPulses() {
  if (millis() - t0 >= 200 and pulse_cont==5) {
    Serial.println("UN:MA:500");
    pulse_cont = 0;
  }
  if (millis() - t0 >= 200 and pulse_cont==4) {
    Serial.println("UN:MA:200");
    pulse_cont = 0;
  }
  if (millis() - t0 >= 200 and pulse_cont==3) {
    Serial.println("UN:MA:100");
    pulse_cont = 0;
  }
}