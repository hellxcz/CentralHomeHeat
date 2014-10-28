/*
 * realLcd.cpp
 *
 * Created: 19. 11. 2013 23:13:35
 *  Author: zdene_000
 */ 

#ifndef LCD_REAL_LCD
#define LCD_REAL_LCD

#include <LiquidCrystal.h>
#include "Lcd.h"

class realLcd : public Lcd {
	
	public:
	realLcd(){
		pLcd = new LiquidCrystal(8, 9, 4, 5, 6, 7);
		pLcd->begin(16, 2);
	}
	
	void setCursor( uint8_t x, uint8_t y ){
		pLcd->setCursor(x, y);
	}

	void print(const char* text){
				
		pLcd->print(text);
	}
	
	void begin(uint8_t cols, uint8_t rows){
		pLcd->begin(cols, rows);
	}
	
	private:
		LiquidCrystal *pLcd;


};

#endif
