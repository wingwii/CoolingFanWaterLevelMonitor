const int led1Pin = 2;
const int led2Pin = 16;

const int inputPin1 = 5;
const int relayOutputPin = 4;
const int bellOutputPin = 14;

void setup() 
{
  SetupInputPins();
}

static void SetupInputPins()
{
  pinMode(inputPin1, INPUT_PULLUP);

  pinMode(relayOutputPin, OUTPUT);
  digitalWrite(relayOutputPin, LOW);

  pinMode(bellOutputPin, OUTPUT);
  digitalWrite(bellOutputPin, LOW);
}

void loop() 
{
  static int prevV = -1;
  auto v = digitalRead(inputPin1);
  if (v != prevV)
  {
    delay(1000);
    auto v2 = digitalRead(inputPin1);
    delay(1000);
    auto v3 = digitalRead(inputPin1);
    if (v == v2 && v == v3) {
      prevV = v;
      if (HIGH == v)
      {
        // ring a bell
        digitalWrite(bellOutputPin, HIGH);
        // stop relay
        digitalWrite(relayOutputPin, LOW);
      }
      else
      {
        digitalWrite(bellOutputPin, LOW);
        digitalWrite(relayOutputPin, HIGH);
      }
    }
  } 
  delay(100);
}
