/*
Example Library EEPROM
Author: Ngoc Tuan
Version:1.0.0
Date:15/12/2020
*/
#include "MyEeprom.h"
void setup() {
	int a=1234;
	long b=-89000;
	float c=3.14;
	double d=192.16;
	Serial.begin(9600);
	MY_EEPROM.begin();
	//save variable type int to address 100
	MY_EEPROM.write(100,a);
	//save variable type int to address 102
	MY_EEPROM.write(102,b);
	//save variable type int to address 106
	MY_EEPROM.write(106,c);
	//save variable type int to address 110
	MY_EEPROM.write(110,d);
}

void loop() {
	//get variable type int from address 100
	int a=MY_EEPROM.read<int>(100);
	//get variable type long from address 100
	long b=MY_EEPROM.read<long>(102);
	//get variable type float from address 100
	float c=MY_EEPROM.read<float>(106);
	//get variable type float from address 100
	double d=MY_EEPROM.read<double>(110);
	//get variable type int from address 100
	Serial.println("a="+String(a)+"	b="+String(b)+"	c="+String(c)+"	d="+String(d));
	delay(500);
}