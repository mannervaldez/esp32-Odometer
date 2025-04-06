#include <Arduino.h>
#include "CadenceManager.h"
#include "OdometerManager.h"

#define PIN_CADENCE 14
#define PIN_ODOMETER 15
#define UPDATE_INTERVAL_MS 1000  // Actualización cada 1 segundo

CadenceManager cadence;
OdometerManager odometer(2.16); // Circunferencia en metros (ajústala a tu rueda)

unsigned long lastUpdate = 0;

void IRAM_ATTR onCadencePulse() {
    cadence.onPulse();
}

void IRAM_ATTR onOdometerPulse() {
    odometer.onPulse();
}

void setup() {
    Serial.begin(115200);

    pinMode(PIN_CADENCE, INPUT_PULLUP);
    pinMode(PIN_ODOMETER, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(PIN_CADENCE), onCadencePulse, FALLING);
    attachInterrupt(digitalPinToInterrupt(PIN_ODOMETER), onOdometerPulse, FALLING);

    Serial.println("Sistema iniciado: Cadencia y Velocidad");
}

void loop() {
    unsigned long now = millis();

    if (now - lastUpdate >= UPDATE_INTERVAL_MS) {
        lastUpdate = now;

        float rpm = cadence.getCadence();
        float speedKmh = odometer.getSpeedKmh();
        float speedMph = odometer.getSpeedMph();

        Serial.print("Cadencia: ");
        Serial.print(rpm, 1);
        Serial.print(" RPM\t");

        Serial.print("Velocidad: ");
        Serial.print(speedKmh, 1);
        Serial.print(" km/h (");
        Serial.print(speedMph, 1);
        Serial.println(" mph)");
    }
}
