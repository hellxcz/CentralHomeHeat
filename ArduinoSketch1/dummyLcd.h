#ifndef LCD_DUMMY_LCD
#define LCD_DUMMY_LCD

#include "Lcd.h"
/*
 * dummyLcd.cpp
 *
 * Created: 19. 11. 2013 23:12:57
 *  Author: zdene_000
 */ 
class dummyLcd : public Lcd {
	public:
	dummyLcd(){}
	void setCursor( uint8_t x, uint8_t y ){
		
	}

	void print(const char[]  value ){
		
	}
	
	void begin(uint8_t cols, uint8_t rows){
		
	}
};

#endif