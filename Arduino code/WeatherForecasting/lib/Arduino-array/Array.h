/*
||
|| @file Array.h
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Provide an easy way of managing raw c++ arrays
|| #
||
|| @license
|| |  This library is free software; you can redistribute it and/or
|| |  modify it under the terms of the GNU Lesser General Public
|| |  License as published by the Free Software Foundation; version
|| |  2.1 of the License.
|| |
|| |  This library is distributed in the hope that it will be useful,
|| |  but WITHOUT ANY WARRANTY; without even the implied warranty of
|| |  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
|| |  Lesser General Public License for more details.
|| |
|| |  You should have received a copy of the GNU Lesser General Public
|| |  License along with this library; if not, write to the Free Software
|| |  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
|| #
||
*/

#ifndef ARRAY_H
#define ARRAY_H

#include <Arduino.h>

template<typename type>
class Array {
	public:
		Array( type* newArray, int newSize ): array(newArray), arraySize(newSize) {/**/}
		int size() const{
			return arraySize;
		}
		type getMax(){
			type max = array[0];
			for (int i=1; i<arraySize; i++){
				if (max < array[i]){
					max = array[i];
				}
			}
			return max;
		}

		type getMaxIndex(){
			type max = array[0];
			type maxIndex = array[0];
			for (int i=0; i<arraySize; i++){
				if (max <= array[i]){
					max = array[i];
					maxIndex = i;
				}
			}
			return maxIndex;
		}
		
		type getMin(){
			type min = array[0];
			for (int i=1; i<arraySize; i++){
				if (min > array[i]){
					min = array[i];
				}
			}
			return min;
		}

		type getMinIndex(){
			type min = array[0];
			type minIndex = array[0];
			for (int i=0; i<arraySize; i++){
				if (min >= array[i]){
					min = array[i];
					minIndex = i;
				}
			}
			return minIndex;
		}
		
		type getAverage(){
			type sum = 0;
			for (int i=0; i<arraySize; i++){
				sum += array[i];
			}
			return (sum/arraySize);
		}
		
		// subscript operator for non-const objects returns modifiable lvalue
		type &operator[]( int index ) {
			// simple error handling
			if (index>=arraySize){
				return array[arraySize-1];
			}else if (index<0){
				return array[0];
			}else{
				return array[index];
			}
		}		
		// subscript operator for const objects returns rvalue
		type operator[]( int index ) const {
			// simple error handling
			if (index>=arraySize || index<0){
				return 0;
			}else{
				return array[index];
			}
		}
		
	private:
		type* array;
		int arraySize;
};

#endif