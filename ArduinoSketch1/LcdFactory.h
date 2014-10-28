/*
 * LcdFactory.cpp
 *
 * Created: 19. 11. 2013 23:33:49
 *  Author: zdene_000
 */ 

#ifndef LCD_FACTORY
#define LCD_FACTORY


#include "Lcd.h"

#ifdef LCD_ENABLED
#include "realLcd.h"
#else
#include "dummyLcd.h"
#endif

static Lcd* lcdInstance;

static Lcd* getLcd()
{
	#ifdef LCD_ENABLED
	lcdInstance = new realLcd();
	#else
	lcdInstance = new dummyLcd();
	#endif
	
	return lcdInstance;
}

#endif