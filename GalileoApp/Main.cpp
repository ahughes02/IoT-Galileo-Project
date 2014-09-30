// Main.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "arduino.h"
#include "NetworkSerial.h"

#define NETWORKSERIAL_PORT 27015

int _tmain(int argc, _TCHAR* argv[])
{
    return RunArduinoSketch();
}

NetworkSerial netSerial;
float temperature = 1.0f;

void setup()
{
	netSerial.begin(9600);
}

// the loop routine runs over and over again forever
void loop()
{
	temperature = (float)analogRead(-1);
	netSerial.print(temperature);
	Sleep(1000);
}