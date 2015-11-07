/*Editor: Earl R. Watkins II Title: ERW_MSGEQ7_example Date: 11/04/2015
 * Datasheet: http://www.mix-sig.com/images/datasheets/MSGEQ7.pdf
 * Use to hook up pins properly, Also contains a recomended circuit.
 * 7 Bands: 63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz, and 16kHz
 * notes: TIP=Left, Ring = Right, Sleeve = GND.
 * This example requires 2 MSGEQ7 ICs.
 * leftRead = Tip= Analog Input
 * rightRead = Ring = Analog Input
 * Strobe = Digital Output
 * Reset = Digital Output
  */
//Libraries
#include <ERW_MSGEQ7.h> // Add Earl's MSGEQ7 library.
//Definitions
#define leftRead A0 // Define analog pin to read from left MSGEQ7.
#define rightRead A1 // Define analog pin to read from right MSGEQ7.
#define Strobe 3 // Define output pin to strobe MSGEQ7 for Frequencies.
#define Reset 2 // Define output pin to reset MSGEQ7 to read 
int leftAmplitudes[7]; //The Library modifies an left channel array.
int rightAmplitudes[7]; // The Library modifies the right channel array.
const unsigned long timeStep = 1000; // 1000ms is 1 second. This controls the sample rate. 
unsigned long Timer; // Timer to do math instead of delay
//Objects
ERW_MSGEQ7 VU; // Rename object

void setup() // Setup -------------------------------------------------------------
{
  Serial.begin(9600); //Begin Serial interface
  VU.begin(leftRead, rightRead, Strobe, Reset); //Begin graphic equilizer for stereo.
           //Requires 2 analog read pins and 2 digital write pins.
  Serial.println("MSGEQ7 started"); //User info.
  Serial.print("Left: "); // Print Channel indicator.
  Serial.println("\t\t\t\t\t\t\t\t\t\t\t\t\t\tRight: "); // Print Channel indicator.  
  Timer=millis(); // Start timer.
}

void loop() // Pete & repete ------------------------------------------------------
{
  if(millis()-Timer>=timeStep)
  {
    VU.getAmplitudes(leftAmplitudes, rightAmplitudes); // Gets amplitudes of stereo.
                      // Must pass the name of two arrays. 
                      // One left and one right.
    for(int i=0; i<7; i++) // Loop through all values of array.
    {
      printHz(i); // Print the Frequency of the value.
      Serial.print(leftAmplitudes[i]); // Print value(0-1023).
    }
    for(int i=6; i>=0; i--) // Loop through all values of array.
    {
      printHz(i); // Print the Frequency of the value.
      Serial.print(rightAmplitudes[i]); // Print value(0-1023).
    }
    Serial.println(); // New Line.
    Timer+=timeStep; // Update timer.
  }
}

void printHz(int sw) // Print the Frequency of the value.
{
  //7 Bands: 63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz, and 16kHz
  switch (sw) 
  {
    case 1:
      Serial.print("\t160Hz: "); //Print the current frequency
      break;
    case 2:
      Serial.print("\t400Hz: "); //Print the current frequency
      break;
    case 3:
      Serial.print("\t1kHz: "); //Print the current frequency
      break;
    case 4:
      Serial.print("\t2.5kHz: "); //Print the current frequency
      break;
    case 5:
      Serial.print("\t6.25kHz: "); //Print the current frequency
      break;
    case 6:
      Serial.print("\t16kHz: "); //Print the current frequency
      break;
    default: 
      Serial.print("63Hz: "); //Print the current frequency
    break;
  }
}
