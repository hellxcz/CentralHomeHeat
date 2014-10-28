#ifndef KeypadReader_h
#define KeypadReader_h

#include "Precompiled.h"

#include "Lcd.h"
#include "LcdFactory.h"

class KeypadReader
{
  public:
    KeypadReader(EventManager *evtManager);
    
    enum lcdButton {
      right = 0,
      up = 1,
      down = 2,
      left = 3,
      select = 4,
      none = 5
    };
	
    void ReadKey();
    KeypadReader::lcdButton GetLastKey() { return lastKey; };
    
  private:
    KeypadReader::lcdButton lastKey;
    EventManager *_eventManager;
};

class KeypadMessage : public Event
{
	public:
		KeypadMessage(){}
		KeypadMessage(const char *cLabel, KeypadReader::lcdButton _lcdButton) : Event(cLabel), lcdButton(_lcdButton){}
		KeypadReader::lcdButton lcdButton;
};

char* GetLcdButtonString(KeypadReader::lcdButton value);

#endif
