//0 low - port is connected
//1 high - port is disconnected

#include <EEPROM.h>

int data;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop()
{
  int address = 10;

  data = EEPROM.read(address);

  if (data == 0) {
    digitalWrite(2, LOW);
  }
  else if (data == 1) {
    digitalWrite(2, HIGH);
  }
  else {
    EEPROM.write(address, 0);
  }


  if (Serial.available())
  {
    char data = Serial.read();
    switch (data)
    {
      case 'C':
        EEPROM.write(address, 0);
        delay(10);
        Serial.println("Opened");
        break;
      case 'D':
        EEPROM.write(address, 1);
        delay(10);
        Serial.println("Closed");
        break;
    }
  }

}
