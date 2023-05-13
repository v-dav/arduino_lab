int soil = 0;
const int  Air = 800; //in reality 790 +/- 2
const int Water = 400; //in reality 380 +/- 2
int intervals = (Air - Water) / 3; //The sensor detection range is divided in 3 sections: dry, wet , water
int prevState = 0;

void setup() 
{
  pinMode(13, OUTPUT);
  Serial.begin(9600); //open serial port, set the baud rate to 9600 bps
}

void loop() 
{
  soil = analogRead(A0); //put sensor in the soil
  int currentState = 0;

  if (soil > Water && soil < (Water + intervals)) // range between  400 - 533
  {
    Serial.println("I'm soaking ! Stop watering !");
    digitalWrite(13, HIGH);
    delay(100);         
    digitalWrite(13, LOW);
    delay(100);
  }
  else if (soil > (Water + intervals) && soil < (Air - intervals)) // range between 533 - 666
  {
    currentState = 1;
    if (currentState != prevState) 
    {
      Serial.println("I'm ok ! Thank you :)");
      prevState = currentState;
    }
  }
  else if (soil > (Air - intervals) && soil < Air) //range between 666 - 800
  { 
    Serial.println("I'm starving ! Feed me, please !");
    digitalWrite(13, HIGH);
    delay(100);         
    digitalWrite(13, LOW);
    delay(100);
  }
  delay (1000);
}

