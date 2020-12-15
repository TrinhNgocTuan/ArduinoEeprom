/*
Library EEPROM
Author: Ngoc Tuan
Version:1.0.0
Date:15/12/2020
*/
#ifndef _MY_EEPROM_H
#define _MY_EEPROM_H
#include <EEPROM.h>
class MyEeprom
{
	public:
	void begin();
	template <class Type>
	void write(int addr,Type value);
	template <class Type> Type read(int addr);
};
void MyEeprom::begin()
{
	EEPROM.begin();
}
template <class Type>
void MyEeprom::write(int addr,Type value)
{
  for(byte i=0;i<sizeof(value);i++)
  {
    EEPROM.write(addr+i, *((byte *)&value+i));
  }
  return value;
}
template <class Type> 
Type MyEeprom::read(int addr)
{
  Type value;
  for(byte i=0;i<sizeof(value);i++)
  {
    *((byte *)&value +i)=EEPROM.read(addr+i);
  }
  return value;
}
static MyEeprom MY_EEPROM __attribute__ ((unused));
#endif