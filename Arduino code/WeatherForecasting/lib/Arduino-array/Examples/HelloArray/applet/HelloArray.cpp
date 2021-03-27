#include <Array.h>

#include "WProgram.h"
void setup();
void loop();
const byte size = 10;
int rawArray[size] = {1,2,3,4,5,6,7,8,9,10};
Array<int> array = Array<int>(rawArray,size);

void setup(){
  Serial.begin(9600);
  Serial.println("The contents of the array:");
  for (byte i=0; i<array.size(); i++){
    Serial.print(array[i]);
    Serial.print(", ");
  }
  Serial.println("\nSpecial functionality:");
  Serial.print("\tMinimum value:");
  Serial.print(array.getMin());
  Serial.println();
  Serial.print("\tMaximum value:");
  Serial.print(array.getMax());
  Serial.println();
  Serial.print("\tAverage value:");
  Serial.print(array.getAverage());
  Serial.println();
}

void loop(){/*no loop*/}

extern void setup(void) __attribute__((weak));
extern void loop(void) __attribute__((weak));
int main(void) {
  init();
    
  if (setup!= NULL) setup();
  
  if (loop != NULL){
	for (;;) loop();
  } else {
    //put sleep code here, in a loop
    for (;;) asm("nop\n");
  }

  return 0;
} 
