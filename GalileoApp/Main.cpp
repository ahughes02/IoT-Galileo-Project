// Main.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "arduino.h"
#include "NetworkSerial.h"

#define NETWORKSERIAL_PORT 27015

int _tmain(int argc, _TCHAR* argv[])
{
    return RunArduinoSketch();
}

// Classes
NetworkSerial netSerial;

// Variables
float temperature = 1.0f;
byte incByte; 		// stores the next byte in the serial buffer
char test; 		// test character to be compared in the while loop
int exitLoop = 0; 	// variable is set to 1 when valid buffer is stored

void setup()
{
	netSerial.begin(9600);
}

// the loop routine runs over and over again forever
void loop()
{
	// Wait for message
	exitLoop = 0;
	while (exitLoop != 1)
	{
		incByte = netSerial.read(); // get the next byte

		test = char(incByte); // store it as a character 

		if (test == 's') // if the next byte is a '#' then its the start of a new string
		{
			exitLoop = 1;
		}
		else
		{
			Sleep(100);
		}
	}

	temperature = (float)analogRead(-1);
	netSerial.println(temperature);
}