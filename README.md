# MakeIT-How-to-forecast-weather-with-Arduino-Nano-33
This repository is dedicated to the second tutorial of my youtube channell MakeIT. This project is about tiny machine learning and how to forecast weather using Arduino Nano 33 BLE Sense.

This repository is dedicated to the second tutorial of my YouTube channel: MakeIT.
This tutorial is called "How to forecast weather with Arduino Nano 33 ?" available [here]().

You can find below the pipeline to develope a TinyML project :

![Pipeline](https://github.com/BaptisteZloch/MakeIT-How-to-forecast-weather-with-Arduino-Nano-33/blob/main/Pipeline.png?raw=true)


## [Python part](https://github.com/BaptisteZloch/MakeIT-How-to-forecast-weather-with-Arduino-Nano-33/tree/main/Python%20model)

This has been designed using Tensorflow and Keras with several layers. This network has been trained on [Istanbul weather dataset](https://www.kaggle.com/vonline9/weather-istanbul-data-20092019).
Then this model has been exported into a none quantized tflite model. After that I have used [xxd tool](https://cygwin.com/packages/summary/xxd.html) to create a .h file containing an hexadecimal array with the the neural network's parameters.
<!--Here is a schema of the neural network :-->

<!--![Neural network](https://github.com/BaptisteZloch/MakeIT-How-to-deploy-a-linear-regression-on-Arduino-Nano-33/blob/main/Python%20model%20and%20files/Neural%20network.png?raw=true)-->

## [Arduino part](https://github.com/BaptisteZloch/MakeIT-How-to-forecast-weather-with-Arduino-Nano-33/tree/main/Arduino%20code/WeatherForecasting)

In this part I have used VS code and platformIO IDE to deploy the model onto the Arduino nano 33 BLE sense. To do it we had to import our model, a library to deploy it and the libraries to use built in sensor of the Arduino Nano 33 BLE Sense. I have choosen EloquentTinyML.h. This library uses Tensorflow lite micro core and simplify the deployement. For another tutorial I will show you how to use directly tensorflow lite micro core.

Here is the result of the inferences (quite accurate) : 

![Results of the prediction](https://github.com/BaptisteZloch/MakeIT-How-to-forecast-weather-with-Arduino-Nano-33/blob/main/Results.png?raw=true)

