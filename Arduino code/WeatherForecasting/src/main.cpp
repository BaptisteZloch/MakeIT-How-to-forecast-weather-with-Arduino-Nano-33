 /*
  *MakeIT 2nd tutorial
  *Title : Weather forecasting 
  *Author : Baptiste ZLOCH (MakeIT owner)
  *Description : Deploying a model that tries to forecast the sky overcast done with tensorflow converted to c++ .h file. Done with EloquentTinyML library, really easy to use. 
  *Date : 28/03/2021
  *Tested with : NANO 33 BLE
  */


#include <Arduino.h>
#include "model.h"
#include <EloquentTinyML.h>
#include <Array.h>

#include <Arduino_HTS221.h>  //library for the humidity and temperature sensor of the NANO 33 BLE Sense
#include <Arduino_LPS22HB.h> //library for the pressure sensor of the NANO 33 BLE Sense

#define INPUTS 3              //number of inputs
#define OUTPUTS 5             //number of outputs
#define Tensor_ARENA 8*1024 //memory you will allocate to the model

Eloquent::TinyML::TfLite<INPUTS, OUTPUTS, Tensor_ARENA> weather_model; //Declare our model

String classes[OUTPUTS] = {"Clear", "Partly cloudy", "Cloudy", "Overcast", "Patchy rain possible"};

String Sky(float array[OUTPUTS])
{
  Array<float> out = Array<float>(array, OUTPUTS); // create an array (object of our library) to ease index manipulation
  int max_index = out.getMaxIndex();
  return classes[max_index];
}

void setup()
{
  Serial.begin(9600); //start the serial communication

  weather_model.begin(model); //start the model

  //intanciate the temperature and humidity sensor
  if (!HTS.begin())
  {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1)
      ;
  }
  //intanciate the pressure sensor
  if (!BARO.begin())
  {
    Serial.println("Failed to initialize pressure sensor!");
    while (1)
      ;
  }
}

void loop()
{
  float temp = HTS.readTemperature();        //read temperature in °C
  float hum = HTS.readHumidity();            //read humidity in %
  float pressure = BARO.readPressure() * 10; //read pressure, *10 to convert it into hPa

  float inputs[INPUTS] = {temp, hum, pressure}; //create an array containing our parameters in the same order than in google colab
  float outputs[OUTPUTS] = {0, 0, 0, 0, 0};     //create an empty array that will contain the 5 outputs of the Neural Network
  weather_model.predict(inputs, outputs);       //predict the inputs and fill the outputs arguments with the neural network output

  //print values :
  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.print(" Pressure : ");
  Serial.print(pressure);
  Serial.print(" Humidity : ");
  Serial.println(hum);
  //print result
  Serial.print("The sky is : ");
  Serial.println(Sky(outputs));
  delay(1000);
}
