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
float temperature; // stores temperature value
int reading; // stores reading from seeed studio sensor
float resistance; // stores resistancefrom seeed studio sensor
int thermistor = 3975; // thermistor value
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

	// Read temp from internal temp sensor
	temperature = (float)analogRead(-1);
	netSerial.print("CPU Temperature is: ");
	netSerial.print(temperature);
	netSerial.print("C");

	netSerial.print(" 0:"); 
	netSerial.print(analogRead(0));
	netSerial.print(" 1:");
	netSerial.print(analogRead(1));
	netSerial.print(" 2:");
	netSerial.print(analogRead(2));
	netSerial.print(" 3:");
	netSerial.print(analogRead(3));
	netSerial.print(" 4:");
	netSerial.print(analogRead(4));
	netSerial.print(" 5:");
	netSerial.print(analogRead(5));

	netSerial.print(" A0:");
	netSerial.print(analogRead(A0));
	netSerial.print(" A1:");
	netSerial.print(analogRead(A1));
	netSerial.print(" A2:");
	netSerial.print(analogRead(A2));
	netSerial.print(" A3:");
	netSerial.print(analogRead(A3));
	netSerial.print(" A4:");
	netSerial.print(analogRead(A4));
	netSerial.print(" A5:");
	netSerial.print(analogRead(A5));

	// let web site know we are done printing
	netSerial.print(" \n");

	// Read temp from Seeed Studio sensor
	/*reading = (float)analogRead(1);
	resistance = (float)(1023 - reading) * 10000 / reading; //get the resistance of the sensor
	temperature = 1 / (log(resistance / 10000) / thermistor + 1 / 298.15) - 273.15; //convert to temperature via datasheet
	netSerial.print("External Temperature is: ");
	netSerial.print(temperature);
	netSerial.print("C ");

	// Read light value from Seeed Studio sensor
	int sensorValue = analogRead(0);
	resistance = (float)(1023 - sensorValue) * 10 / sensorValue;
	netSerial.print("Light sensor resistance is: ");
	netSerial.println(resistance, DEC);*/
}