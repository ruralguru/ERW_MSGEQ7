/*Editor: Earl R. Watkins II Title: ERW_MSGEQ7.h Date: 11/04/2015
	Thanks to: Dan Wagner

	Mixed Signal Integration MSGEQ7 Graphic Equalizer Library
	7 Bands: 63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz, and 16kHz

	Notes:

	Based on: Knowlege gained from Kansas State University ECE 241 Intro Computer Engg F'15

	This example code uses the "beerware" license. Use it, modify it, and/or reference it.
	If you find it useful, buy me an ice cold tasty beverage someday.
*/

#ifndef ERW_MSGEQ7_h
#define ERW_MSGEQ7_h


//Include needed libraries with ifndef

class ERW_MSGEQ7
{
	public: //Can be called upon.

	//Public Functions
		ERW_MSGEQ7(void);
		// Base type
		void beginMono(int monoRead, int strobe, int reset);
			// Call VU.begin() to initialize MSGEQ7 before use.
		void begin(int lRead, int rRead, int strobe, int reset);
			// Call VU.begin() to initialize MSGEQ7 before use.
		void getAmplitudes(int (&leftArray)[7], int (&rightArray)[7]);
			// Read the amplitudes of each of the 7 frequencies for each channel.
		void getMonoAmplitudes(int (&monoArray)[7]);
			// Read the amplitudes of each of the 7 frequencies.
		void ERW_MSGEQ7::getSingleStereoAmplitude(int(&leftArray)[7], int (&rightArray)[7], int channelNumber);
			//TODO: stuff
		void ERW_MSGEQ7::getSingleMonoAmplitude(int(&monoArray)[7], int channelNumber);
			//TODO: stuff
	//Public Variables

	private:
	//Private Functions
		float getBaseFrequency( int frequencyRead);
		//Verify the base frequency is correct.
	//Private Variables
		int rRead; // Right analog read pin.
		int lRead; // Left analog read pin.
		int monoRead; // Mono analog read pin.
		int strobe; // Strobe pin to alternate frequencies.
		int reset; //Reset pin to start back at beginning.
};
//Definitions
#endif
