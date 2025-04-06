#ifndef ODOMETER_MANAGER_H
#define ODOMETER_MANAGER_H

#include "CadenceManager.h"

class OdometerManager : public CadenceManager {
public:
    OdometerManager(float wheelCircumferenceMeters)
        : circumference(wheelCircumferenceMeters) {}

    float getSpeedKmh() {
        float rpm = getCadence();
        float speed_mps = (rpm * circumference) / 60.0; // m/s
        return speed_mps * 3.6; // km/h
    }

    float getSpeedMph() {
        float speedKmh = getSpeedKmh();
        return speedKmh * 0.621371; // km/h a mph
    }

private:
    float circumference; // en metros
};

#endif // ODOMETER_MANAGER_H
