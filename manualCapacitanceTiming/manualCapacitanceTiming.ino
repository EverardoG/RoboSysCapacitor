const int ViPin = 3;
const int VoPin = A5;
//int VoRaw = 0;
//float VoVoltage = 0.0f;
long StartChargeTime;
long StartDisChargeTime;
long ChargeTime;
long DisChargeTime;

void setup() {
  // put your setup code here, to run once:

  // Set up the serial port
  Serial.begin(9600);

  // Set up Vi pin as arduino output
  pinMode(ViPin, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Charging Capacitor");

  // record the start time
  StartChargeTime = millis();

  // Set the circuit input pin to 5V
  digitalWrite(ViPin, HIGH);

  // Wait for the capacitor to charge
  while (analogRead(VoPin) < 1023) { }
  ChargeTime = millis() - StartChargeTime;
  Serial.print("Charge Time: "); Serial.println(ChargeTime);

  Serial.println("Discharging Capacitor");

  // record start of discharge
  StartDisChargeTime = millis();

  // Set the input pin to 0V
  digitalWrite(ViPin, LOW);

  // Wait for the capacitor to discharge
  while (analogRead(VoPin) > 0) { }
  DisChargeTime = millis() - StartDisChargeTime;
  Serial.print("Discharge Time: "); Serial.println(DisChargeTime);
}

//float rawToVoltage(int raw_value) {
//  return ((float) raw_value) * 5.0f / 1023.0f;
//}
//
//void printCurrentState() {
//  // Print current time | raw value | voltage
//  Serial.print("Time: "); Serial.print(millis()-StartTime); Serial.print(" | ");
//  VoRaw = analogRead(VoPin);
//  Serial.print("Raw: "); Serial.print(VoRaw); Serial.print(" | ");
//  VoVoltage = rawToVoltage(VoRaw);
//  Serial.print("Voltage: "); Serial.println(VoVoltage);
//}

