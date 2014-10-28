
#include "Precompiled.h"
#include "KeypadReader.h"

KeypadReader::KeypadReader(EventManager *eventManager) : lastKey(none)
{
	_eventManager = eventManager;
}

char* GetLcdButtonString(KeypadReader::lcdButton value)
	{
		char* msg;
		switch (value)
		{
			case KeypadReader::left :
				msg = "left";
				break;
			case KeypadReader::right :
				msg = "right";
				break;
			case KeypadReader::down :
				msg = "down";
				break;
			case KeypadReader::select :
				msg = "select";
				break;
			case KeypadReader::up :
				msg = "up";
				break;
			case KeypadReader::none :
				msg = "none";
				break;
		}
		
		return msg;
	}

void KeypadReader::ReadKey()
{
	int adc_key_in = analogRead(0);      // read the value from the sensor
	
	lcdButton currentKey = none;
	
	// my buttons when read are centered at these values: 0, 144, 329, 504, 741
	// we add approx 50 to those values and check to see if we are close
	if (adc_key_in > 1000) { currentKey = none; } // We make this the 1st option for speed reasons since it will be the most likely result
	else if (adc_key_in < 50)  { currentKey = right; }
	else if (adc_key_in < 250) { currentKey = up; }
	else if (adc_key_in < 450) { currentKey = down; }
	else if (adc_key_in < 650) { currentKey = left; }
	else if (adc_key_in < 850) { currentKey = select; }

	if (lastKey == none && currentKey != none)
	{
		// got key down
		Event* keyEvent = new KeypadMessage("key.down", currentKey);
		_eventManager->Trigger(keyEvent);
		
		delete keyEvent;
	}
	else if (lastKey != none && currentKey == none)
	{
		// got key up
		Event* keyEvent = new KeypadMessage("key.up", currentKey);
		_eventManager->Trigger(keyEvent);
		
		delete keyEvent;
	}

	lastKey = currentKey;
	
}