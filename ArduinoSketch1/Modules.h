/*
 * Modules.h
 *
 * Created: 2. 12. 2013 19:53:25
 *  Author: zdene_000
 */ 

#ifndef MODULES_H_
#define MODULES_H_

#include "MenuItem.h"
#include "TemperatureMonitor.h"
#include "MenuRenderer.h"

static vector<TemperatureItem*> GetI2CTemperaturesAddresses()
{
	std::vector<TemperatureItem*> result;
	
	result.push_back(new TemperatureItem(5, "some 5", {0, 1} ));
	result.push_back(new TemperatureItem(6, "some 6", {0, 1} ));
	result.push_back(new TemperatureItem(7, "some 7", {0, 1} ));
	result.push_back(new TemperatureItem(8, "some 8", {0, 1} ));

	return result;
}

static TemperatureMonitor* TemperatureMonitorFactory()
{
	TemperatureMonitor* pTemperatureMonitor = new TemperatureMonitor();

	vector<TemperatureItem*> items = GetI2CTemperaturesAddresses();
	
	for(auto iter = items.begin();
	iter != items.end();
	iter++)
	{
		pTemperatureMonitor->AddItem(*iter);
	}

	return pTemperatureMonitor;
}

static MenuItem* MenuFactory()
{
	MenuItem* pMonitorMenuItem = new MenuItem("Monitor");
	
	MenuItem* pTemperatureMenuItem = new MenuItem("Temperature");
	MenuItem* pRelaysStateMenuItem = new MenuItem("Relays");
	
	pMonitorMenuItem->AddChildren(pTemperatureMenuItem);
	pMonitorMenuItem->AddChildren(pRelaysStateMenuItem);
	
	MenuItem* pSettingsMenuItem = new MenuItem("Settings");
	
	MenuItem* pMainTemperatureMenuItem = new MenuItem("Main Temp");
	
	pSettingsMenuItem->AddChildren(pMainTemperatureMenuItem);
	
	MenuItem* pRoot = new MenuItem("Root");
	pRoot->AddChildren(pMonitorMenuItem);
	
	return pRoot;
}
//
#endif /* MODULES_H_ */