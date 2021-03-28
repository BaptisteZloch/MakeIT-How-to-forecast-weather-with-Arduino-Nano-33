# Arduino Array
A "fork" of the Arduino Array Library (http://playground.arduino.cc/Code/Array) by Alexander Brevig. Updated this verion to work with the more recent versions of Arduino. I've currently tested the library with Arduino v1.6.5.

## Install
Put the Array folder in "hardware\libraries\".
In the Arduino IDE, create a new sketch (or open one) and select from the menubar "Sketch->Import Library->Array".
Once the library is imported, an '#include <Array.h>' line will appear at the top of your Sketch.

## Use
`Array<datatype> variableName = Array<datatype>( array , size );`

## Functions
`variableName.getMin();`

`variableName.getMinIndex();`

`variableName.getMax();`

`variableName.getMaxIndex();`

`variableName.getAverage();`


