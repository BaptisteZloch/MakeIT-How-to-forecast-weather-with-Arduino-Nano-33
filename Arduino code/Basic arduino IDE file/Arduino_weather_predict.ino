#include <EloquentTinyML.h>
#include "model.h"
#include <Arduino_HTS221.h>
#include <Arduino_LPS22HB.h>
#include <Array.h>

#define NUMBER_OF_INPUTS 3
#define NUMBER_OF_OUTPUTS 5
#define TENSOR_ARENA_SIZE 8*1024

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setup() {
  Serial.begin(9600);
  Serial.println("Communication started");
  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }
  if (!BARO.begin()) {
    Serial.println("Failed to initialize pressure sensor!");
    while (1);
  }
  ml.begin(model);
}

void loop() {
  float temperature = HTS.readTemperature();
  float humidity = HTS.readHumidity();
  float pressure = BARO.readPressure() * 10;

  float input[NUMBER_OF_INPUTS] = {temperature, humidity, pressure};
  float output[NUMBER_OF_OUTPUTS] = {0, 0, 0, 0, 0};
  ml.predict(input, output);

  Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.print(" °C Humidity : ");
  Serial.print(humidity);
  Serial.print(" % Pressure : ");
  Serial.println(pressure);
  Serial.print("The sky is : ");
  Serial.println(value(output));
  delay(1000);
}

String value(float out[5]) {
  Array<float> my_classes = Array<float>(out, NUMBER_OF_OUTPUTS);
  if (my_classes.getMaxIndex() == 0) {
    return "Clear";
  } else if (my_classes.getMaxIndex() == 1) {
    return "Partly cloudy";
  } else if (my_classes.getMaxIndex() == 2) {
    return "Mostly cloudy";
  } else if (my_classes.getMaxIndex() == 3) {
    return "Overcast";
  } else {
    return "Foggy";
  }
}
