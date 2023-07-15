#include "mbed.h"
#include "Accelerometer.h"

Accelerometer accelerometer(I2C_SDA, I2C_SCL);

float computeAngle(float X, float Y, float Z) {
    // Calculate angle in degrees
    float pitch = atan2(-X, sqrt(Y * Y + Z * Z)) * 180 / M_PI;
    return pitch;
}

int main() {
    // start the accelerometer
    accelerometer.init();

    while (1) {
        // Read accelerometer
        float X, Y, Z;
        accelerometer.readXYZGravity(&X, &Y, &Z);

        float pitch = computeAngle(X, Y, Z);

        // angle
        printf("Pitch Angle: %.2f degrees\r\n", pitch);

        wait(2.0);
    }
}