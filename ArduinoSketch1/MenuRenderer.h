/* 
* MenuRenderer.h
*
* Created: 16. 1. 2014 19:12:46
* Author: zdene_000
*/


#ifndef __MENURENDERER_H__
#define __MENURENDERER_H__

#include "MenuItem.h"
#include "Event.h"
#include "Lcd.h"
#include "KeypadReader.h"

class MenuRenderer
{
	class MenuRendererButtonListener : public EventTask
	{
		private:
			MenuRenderer* pMenuRenderer = nullptr;
		
		public:
		MenuRendererButtonListener(MenuRenderer* menuRenderer)
		: pMenuRenderer(menuRenderer)
		{}
		
		void execute(Event* evt)
		{
			KeypadMessage* pKeypadMessage = (KeypadMessage*)evt;
			pMenuRenderer->ButtonPressed(pKeypadMessage->lcdButton);
		}
	};
	
//variables
public:
protected:
	MenuItem* pRootMenuItem;
	MenuItem* pCurrentMenuItem;
	Lcd* pLcd;
	EventManager* pEventManager;
	
private:

//functions
public:
	MenuRenderer(Lcd* lcd, MenuItem* pMenuItem, EventManager* eventManager)
	: pLcd(lcd), pRootMenuItem(pMenuItem), pCurrentMenuItem(pMenuItem), pEventManager(eventManager)
	{
		/// subscribe to keypad events
		eventManager->Subscribe("key.down", new MenuRendererButtonListener(this));
	}
		
	~MenuRenderer();
	
	void ButtonPressed(KeypadReader::lcdButton button)
	{
		// react on that :D
		
		// navigation thru menuItems
		// render current menu item
		// perform current action of item
		
		
		
		// move buttons basically moves the cursor
		// when menuItem has more lines, it should scroll
		// when end of items is reached, next item should be set as active
		// when cursor is on changeable value, hit select button will switch to change value mode
		// value is changed by up/down
		// confirmed by select
		// canceled by left/right
	}
	
	
protected:
private:

}; //MenuRenderer

#endif //__MENURENDERER_H__
