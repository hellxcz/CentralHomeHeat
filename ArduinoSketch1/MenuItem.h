/*
 * MenuItemBase.h
 *
 * Created: 2. 12. 2013 19:48:38
 *  Author: zdene_000
 */ 


#ifndef MENUITEMBASE_H_
#define MENUITEMBASE_H_

#include "ModuleBase.h"

#include <WString.h>
#include <vector>

using std::vector;

class MenuItem
{
	public:
	 MenuItem(String _name)
	 : Name(_name), Children(vector<MenuItem*>())
	 {}

	 MenuItem(String _name, ICanRenderToLcd* iCanRenderToLcd )
		 : Name(_name), Children(vector<MenuItem*>()), pICanRenderToLcd(iCanRenderToLcd)
		 {}
		
	vector<MenuItem*> GetChildren()
	{
		return Children;
	}
	
	void AddChildren(MenuItem* menuItem)
	{
		menuItem->SetParent(this);
		Children.push_back(menuItem);
	}
	
	void SetICanRenderToLcd(ICanRenderToLcd* iCanRenderToLcd)
	{
		pICanRenderToLcd = iCanRenderToLcd;
	}
		
	ICanRenderToLcd* GetICanRenderToLcd()
	{
		return pICanRenderToLcd;
	}
		
	void SetParent(MenuItem* parent)
	{
		Parent = parent;
	}
	MenuItem* GetParent()
	{
		return Parent;
	}
		
	protected:
		String Name;
		MenuItem* Parent = nullptr;
		vector<MenuItem*> Children;
		ICanRenderToLcd* pICanRenderToLcd;
};



#endif /* MENUITEMBASE_H_ */