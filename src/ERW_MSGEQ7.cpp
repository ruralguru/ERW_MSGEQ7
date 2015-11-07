/*Editor: Earl R. Watkins II Title: ERW_MSGEQ7.h Date: 11/04/2015
	Thanks to: Dan Wagner
	
	Mixed Signal Integration MSGEQ7 Graphic Equalizer Library
	7 Bands: 63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz, and 16kHz
	
	Notes:
	
	Based on: Knowlege gained from Kansas State University ECE 241 Intro Computer Engg F'15
			  
	This example code uses the "beerware" license. Use it, modify it, and/or reference it. 
	If you find it useful, buy me an ice cold tasty beverage someday.
*/

#include <ERW_MSGEQ7.h>
#include <Arduino.h>

// Base library Type
ERW_MSGEQ7::ERW_MSGEQ7(void)
{

}

// Initialize library for mono
void ERW_MSGEQ7::beginMono(int monoRead, int strobe, int reset)
{
	ERW_MSGEQ7::monoRead = monoRead; // Assign mono analog read pin.
	ERW_MSGEQ7::strobe = strobe; // Assign strobe pin.
	ERW_MSGEQ7::reset = reset; // Assign reset pin.
	pinMode(monoRead,INPUT); // Set monoRead as INPUT.
	pinMode(strobe,OUTPUT); // Set strobe as OUTPUT.
	digitalWrite(strobe,HIGH); // Start strobe in HIGH state.
	pinMode(reset,OUTPUT); // Set reset as OUTPUT.
	pinMode(reset,LOW); // Start reset in LOW state.
}

// Initialize library for stereo
void ERW_MSGEQ7::begin(int lRead, int rRead, int strobe, int reset)
{
	ERW_MSGEQ7::lRead = rRead; // Assign right analog read pin.
	ERW_MSGEQ7::rRead = lRead; // Assign left analog read pin.
	ERW_MSGEQ7::strobe = strobe; // Assign strobe pin.
	ERW_MSGEQ7::reset = reset; // Assign reset pin.
	pinMode(rRead,INPUT); // Set rRead as INPUT.
	pinMode(lRead,INPUT); // Set lRead as INPUT.
	pinMode(strobe,OUTPUT); // Set strobe as OUTPUT.
	digitalWrite(strobe,HIGH); // Start strobe in HIGH state.
	pinMode(reset,OUTPUT); // Set reset as OUTPUT.
	pinMode(reset,LOW); // Start reset in LOW state.
}

void ERW_MSGEQ7::getMonoAmplitudes(int(&monoArray)[7])
{
	noInterrupts(); // Make sure interrupts don't interfere.
	digitalWrite(ERW_MSGEQ7::reset,HIGH); // Start reset in HIGH state.
	digitalWrite(ERW_MSGEQ7::reset,LOW); // Start reset in LOW state.
	for(int i = 0; i < 7; i++ )
	{
		digitalWrite(ERW_MSGEQ7::strobe,LOW); // Start strobe in LOW state.
		delayMicroseconds(37);// Allow results to settle.
		delayMicroseconds(37);//********************************
		monoArray[i] = analogRead(ERW_MSGEQ7::monoRead); // Assign ADC value to array.
		digitalWrite(ERW_MSGEQ7::strobe,HIGH); // Start strobe in HIGH state.
	}
	interrupts(); // Allow interrupts.
}

void ERW_MSGEQ7::getAmplitudes(int(&leftArray)[7], int (&rightArray)[7])
{
	noInterrupts(); // Make sure interrupts don't interfere.
	digitalWrite(ERW_MSGEQ7::reset,HIGH); // Start reset in HIGH state.
	digitalWrite(ERW_MSGEQ7::reset,LOW); // Start reset in LOW state.
	for(int i = 0; i < 7; i++ )
	{
		digitalWrite(ERW_MSGEQ7::strobe,LOW); // Start strobe in LOW state.
		delayMicroseconds(37);// Allow results to settle.
		leftArray[i] = analogRead(ERW_MSGEQ7::lRead); // Assign ADC value to left array.
		rightArray[i] = analogRead(ERW_MSGEQ7::rRead); // Assign ADC value to right array.
		digitalWrite(ERW_MSGEQ7::strobe,HIGH); // Start strobe in HIGH state.
	}
	interrupts();// Allow interrupts.
}

float ERW_MSGEQ7::getBaseFrequency(int frequencyRead)
{
	noInterrupts();
	bool goOn=1;
	int firstReading = analogRead(frequencyRead);
	do
	{
		
	}
	while(goOn);
	interrupts();
}
