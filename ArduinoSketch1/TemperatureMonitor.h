/*
 * TemperatureMonitor.h
 *
 * Created: 5. 12. 2013 9:16:21
 *  Author: zdene_000
 */ 


#ifndef TEMPERATUREMONITOR_H_
#define TEMPERATUREMONITOR_H_

#include <Arduino.h>

#include <map>
#include <vector>
#include <WString.h>

#include "ModuleBase.h"
#include "Wire.h"

class TemperatureItem
{
	public:
	TemperatureItem(char address, String name, std::vector<char> channels)
	: Address(address), Name(name), Channels(channels)
	{

	}
	
	char Address;
	String Name;
	std::vector<char> Channels;
};

class TemperatureReader
{
	public:
		TemperatureReader();
		
		void Read(TemperatureItem* temperatureItem);
		void ReadChannel(char address, char channel);
		
		void OnReceive(int numOfBytes);

	protected:
		TemperatureItem* currentTemperatureItem = nullptr;
};

void OnReceiveHelperCallback(int count);
void OnReceiveHelper (TemperatureReader* __ptTemperatureItemReader);

class TemperatureMessage
{
	public:
		TemperatureMessage(int analogValue, String name)	
		: AnalogValue(analogValue), Name(name)
		{}
			
		int AnalogValue;
		String Name;
};

class TemperatureMonitor : public ModuleTickBase, 
							public ICanRenderToLcd
{
	public:
		TemperatureMonitor()
		{
			//pTemperatureItemReader = new TemperatureItemReader();;
			items = std::map<String, TemperatureItem*>();
		}
		~TemperatureMonitor(){}
		void Tick(){
			// important to have the read trigger
			
			for(auto iter = items.begin(); 
				iter != items.end();
				++iter)
			{
				// read value on current address		
				//auto address = iter->second->Address;
			}
			
		}
		void AddItem(TemperatureItem* item)
		{
			items.insert(std::pair<String, TemperatureItem*>(item->Name, item));
		}
		
		void Render(Lcd* lcd);
	protected:
		TemperatureReader pTemperatureItemReader;
		std::map<String,TemperatureItem*> items;
};

static TemperatureMonitor* getTemperatureMonitor()
{
	
}

#endif /* TEMPERATUREMONITOR_H_ */