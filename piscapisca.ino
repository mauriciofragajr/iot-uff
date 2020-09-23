const int LED_EXTERNAL = 22;
const int LED_BUILTIN = 2;

class Led {
  private:
    int pin;
  public:
    Led(int p) {
      pin = p;
    }
    void turnOn() {
      digitalWrite(pin, HIGH);
    }
    void turnOff() {
      digitalWrite(pin, LOW);
    }
    void turnOnAndFlash() {
      turnOn();
      delay(1000);
      turnOff();
      delay(300);
      turnOn();
      delay(1000);
      turnOff();
    }
    static void flashTogether(Led leds[], int ledCount) {
        for (int thisPin = 0; thisPin < ledCount; thisPin++) {
          leds[thisPin].turnOn();
        }
        delay(1000);
        for (int thisPin = 0; thisPin < ledCount; thisPin++) {
          // turn the pin on:
          leds[thisPin].turnOff();
        }
    }

    static void alternateFlash(Led ledUm, Led ledDois) {
      ledUm.turnOn();
      ledDois.turnOff();
      delay(300);
      ledDois.turnOn();
      ledUm.turnOff();
    }

};

void setup() {
  pinMode(LED_EXTERNAL, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Led internalLed(LED_BUILTIN);
  Led externalLed(LED_EXTERNAL);
  Led leds[2] = {internalLed, externalLed};

  internalLed.turnOnAndFlash();
  
  delay(1000);
  
  externalLed.turnOnAndFlash();
  
  delay(1000);

  for (int i = 0; i < 4; i++) {
    Led::flashTogether(leds, 2);
    delay(300); 
  }
  
  delay(1000);

  for (int i = 0; i < 4; i++) {
    Led::alternateFlash(internalLed, externalLed);
    delay(300);
  }

  delay(1000);

  // 4 - piscar led interno e externo em frequências diferentes
  // REFATORAR
  internalLed.turnOn();
  delay(300);
  externalLed.turnOn();
  delay(300);
  externalLed.turnOff();
  delay(300);
  internalLed.turnOff();
  externalLed.turnOn();
  delay(300);
  externalLed.turnOff();
  internalLed.turnOn();
  delay(300);
  externalLed.turnOn();
  delay(300);
  externalLed.turnOff();
  delay(300);
  internalLed.turnOff();
  externalLed.turnOn();
  delay(300);
  externalLed.turnOff();
  internalLed.turnOn();
  delay(300);
  externalLed.turnOff();
  internalLed.turnOff();
  
  delay(1000);
  
}
