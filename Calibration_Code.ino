void setup() {
Serial.begin(9600);
}

void loop() {
int val;

val = analogRead(0);
Serial.print(val);
Serial.print("\n");
delay(10000);
}
