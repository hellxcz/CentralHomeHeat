/*
* Main.cpp
*
* Created: 11/14/2013 4:19:31 PM
*  Author: zdene_000
*/

#ifndef SKETCH_H_


#include "ScrachPad.h"

#include "Sketch.h"


#include "Precompiled.h"

//#include "Headers/ModuleManager.h"
#include "KeypadReader.h"

//#include "ScrachPad.h"

#define DS1307_ADDRESS 0x68
byte zero = 0x00; //workaround for issue #527

// Configuration variables for MCP3424
#define mcp_address  0x68 // address of this MCP3424. For setting address see datasheet

#include "MCP3424.h"

byte gain = 0; // gain = x1
byte resolution = 3; // resolution = 18bits, 3SPS

MCP3424 ADC1(mcp_address , gain, resolution); // create MCP3424 instance.


EventManager* pEvtManager;
KeypadReader* pNavigator;

Lcd* pLcd;
MenuItem* pRootMenuItem;

TemperatureMonitor* pTemperatureMonitor;

MenuRenderer* pMenuRenderer;

TemperatureReader* pTemperatureReader;
TemperatureItem* pTemperatureItem;

byte decToBcd(byte val){
	// Convert normal decimal numbers to binary coded decimal
	return ( (val/10*16) + (val%10) );
}

byte bcdToDec(byte val)  {
	// Convert binary coded decimal to normal decimal numbers
	return ( (val/16*10) + (val%16) );
}


String AddZero(int val)
{
	if (val < 10)
	{
		return String("0") + String(val);
	}
	
	return String(val);
}

void setup()
{
	Wire.begin();
	
	pEvtManager = new EventManager();
	pNavigator = new KeypadReader(pEvtManager);
	pLcd = getLcd();

	pRootMenuItem = MenuFactory();
	pMenuRenderer = new MenuRenderer(pLcd, pRootMenuItem, pEvtManager);
	
	//pTemperatureMonitor = TemperatureMonitorFactory();

	//setDateTime(); //MUST CONFIGURE IN FUNCTION


	//pEvtManager->Subscribe(new Subscriber("key.down", new ButtonListener()));
	
	// just testing of evtManager
	
	//KeypadReader::lcdButton currentKey = KeypadReader::left;
	//pEvtManager->Subscribe(new Subscriber("key.down", pButtonListener));
	//
	//Event* keyEvent = new KeypadEvent("key.down", currentKey);
	////Event* keyEvent = new Event("key.down");
	
	//pEvtManager->trigger(keyEvent);
	
	
	// just testing of evtManager end

}

void loop()
{
	pNavigator->ReadKey();
	
	char buff[17];
	
	long CH1 = ADC1.getChannelmV(0);
	
	String(CH1).toCharArray(buff, 5);
	
	pLcd->setCursor(0,0);
	pLcd->print("            ");
	pLcd->setCursor(0,0);
	
	pLcd->print(buff);
	pLcd->print(" mV");
	
	delay(300);
	//pTemperatureMonitor->Tick();


}


//void loop(){
	//printDate();
	//delay(1000);
//}
//


//// i2c scanner
//void loop()
//{
	//byte error, address;
	//int nDevices;
//
	//Serial.println("Scanning...");
//
	//nDevices = 0;
	//for(address = 1; address < 127; address++ )
	//{
		//// The i2c_scanner uses the return value of
		//// the Write.endTransmisstion to see if
		//// a device did acknowledge to the address.
		//Wire.beginTransmission(address);
		//error = Wire.endTransmission();
//
		//if (error == 0)
		//{
			//Serial.print("I2C device found at address 0x");
			//if (address<16)
			//Serial.print("0");
			//Serial.print(address,HEX);
			//Serial.println("  !");
//
			//nDevices++;
		//}
		//else if (error==4)
		//{
			//Serial.print("Unknow error at address 0x");
			//if (address<16)
			//Serial.print("0");
			//Serial.println(address,HEX);
		//}
	//}
	//if (nDevices == 0)
	//Serial.println("No I2C devices found\n");
	//else
	//Serial.println("done\n");
//
	//delay(5000);           // wait 5 seconds for next scan
//}

#endif