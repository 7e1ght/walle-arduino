#include <Arduino.h>
#include "MPU6050.h"

#define TO_DEG 57.29577951308232087679815481410517033f

MPU6050 accel;

void setup() {
    Serial.begin(9600);

    accel.initialize(); // первичная настройка датчика
    Serial.println(accel.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}

void loop() {
    int16_t ax, ay, az;
    accel.getAcceleration(&ax, &ay, &az);

    ax /= 8192;
    ay /= 8192;
    az /= 8192;

    Serial.print("ay: ");
    Serial.println(ay);

    Serial.print("ax: ");
    Serial.println(ax);

    Serial.print("az: ");
    Serial.println(az);

    Serial.println();
    Serial.println();
    Serial.println();

    delay(5);
}