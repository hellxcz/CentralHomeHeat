/*
 * CommonLcd.h
 *
 * Created: 19. 11. 2013 23:04:13
 *  Author: zdene_000
 */ 

//#pragma once
#ifndef LCD_CLASS
#define LCD_CLASS

#include <inttypes.h>
//#include <string.h>

class Lcd {
	public :
		//Lcd(){};
		virtual void setCursor(uint8_t x, uint8_t y) = 0;
		virtual void print(const char* val) = 0;
		virtual void begin( uint8_t cols, uint8_t rows) = 0;
		//virtual ~Lcd(){}
};

#endif