int sensor_value = 0;

void setup() {
  pinMode(13, OUTPUT); //DIGITAL LED PIN IS OUTPUT
  Serial.begin(9600); //sending and recieving serial data
  digitalWrite(13, LOW);
}

void loop() {
  sensor_value = analogRead(A0);
  int counter = 1;
  int counter2;

  Serial.println(sensor_value);

  if (sensor_value > 400 && sensor_value < 800)
  {
      Serial.println("Feed Me");
      digitalWrite(13, HIGH);
  }
  else if (sensor_value <= 400)
  {
    counter2 = 1;
    Serial.println("I'm starving");
    while(counter2 < 10)
    {
      counter2++;
      digitalWrite(13, HIGH);
      delay(100);         
      digitalWrite(13, LOW);
      delay(100);
    }
  }
  else
    Serial.println("Thank You, Vlad, I'm OK");
}

