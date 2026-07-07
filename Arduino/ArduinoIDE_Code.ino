#include <SoftwareSerial.h>

// BLE on pins 2 (RX), 3 (TX)
SoftwareSerial BLE(2, 3);

void setup()
{
    Serial.begin(9600);   // Serial Monitor
    BLE.begin(9600);      // BT-05

    delay(2000);

    Serial.println("BT-05 Ready");
}

void loop()
{
    Serial.println("Sending to BT-05...");
    delay(5000);

    Serial.println("Reading from BT-05...");
    delay(5000);

    // PC → BLE
    if (Serial.available())
    {
        char c = Serial.read();
        BLE.write(c);
        Serial.println("Sending to BT-05...");
    }

    // BLE → PC
    if (BLE.available())
    {
        char c = BLE.read();
        Serial.println("Reading from BT-05...");
        Serial.write(c);
    }
}
