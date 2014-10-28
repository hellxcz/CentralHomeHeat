/*
 * ModuleBase.h
 *
 * Created: 17. 12. 2013 8:41:39
 *  Author: zdene_000
 */ 

#ifndef __MODULEBASE_H__
#define __MODULEBASE_H__

#include "Lcd.h"

class ModuleBase
{
	public:

	protected:
	private:
};

class ModuleTickBase : ModuleBase{
	public:
		virtual void Tick(){};
};
	
class ICanRenderToLcd
{
	public:
		virtual void Render(Lcd* lcd) = 0;
};

#endif