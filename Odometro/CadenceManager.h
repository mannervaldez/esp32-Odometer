#ifndef CADENCE_MANAGER_H
#define CADENCE_MANAGER_H

#include <Arduino.h>

class CadenceManager {

private:

    static constexpr unsigned long INACTIVITY_MICROS = 4'000'000; // 3 segundos
    unsigned long timeInterval;
    unsigned long lastPulseTime;
    float rpm;

    bool isInactive(unsigned long now) const {
        return (now - lastPulseTime) > INACTIVITY_MICROS;
    }

    bool isSlowingDown(unsigned long now) const {
        return (now - lastPulseTime) > timeInterval;
    }

    float toRPM(float intervalMicros) const {
        if (intervalMicros <= 0.0f) return 0.0f;
        float intervalSeconds = intervalMicros / 1e6;
        return 60.0f / intervalSeconds;
    }

public:

    CadenceManager()
        : timeInterval(0), lastPulseTime(0), rpm(0.0f)
    {}

    void onPulse() {
        unsigned long now = micros();

        if (lastPulseTime == 0) {
            // Primer pulso recibido
            lastPulseTime = now;

        } else if (isInactive(now)) {
            // El tiempo entre pulsos fue demasiado largo
            rpm = 0.0f;
            timeInterval = 0;
            lastPulseTime = now;

        } else {
            // Pulso válido, actualizar cadencia
            timeInterval = now - lastPulseTime;
            rpm = toRPM(timeInterval);
            lastPulseTime = now;
        }
    }

    float getCadence() {
        unsigned long now = micros();

        if (rpm == 0.0f) {
            return 0.0f;

        } else if (isSlowingDown(now)) {
            if( isInactive(now)) {
                return 0.0f;
            } else {
                return toRPM(now - lastPulseTime);
            }

        } else {
            return rpm;
        }
    }

};

#endif // CADENCE_MANAGER_H
