
/*
 * TemperatureMonitor.cpp
 *
 * Created: 7. 1. 2014 16:40:17
 *  Author: zdene_000
 */ 

#include "TemperatureMonitor.h"

TemperatureReader* _pTemperatureReader;

void OnReceiveHelperCallback(int count)
{
	_pTemperatureReader->OnReceive(count);
}

void OnReceiveHelper(TemperatureReader* __ptTemperatureItemReader)
{
	_pTemperatureReader = __ptTemperatureItemReader;
	Wire.onReceive(OnReceiveHelperCallback);
}

TemperatureReader::TemperatureReader()
{
	OnReceiveHelper(this);
}

void TemperatureReader::OnReceive(int numOfBytes)
{
	//byte some = 'd';
	
	//byte[32] buffer ;
	//
	//Wire.readBytes(buffer, numOfBytes
	
	int analogValue;
	char high, low, config;
	
	//Wire.requestFrom((int)address, (int) 3);
	high = Wire.read();
	low = Wire.read();
	config = Wire.read();  // for possible debugging
	Wire.endTransmission();
	
	analogValue = high;
	analogValue = analogValue * 256 + low;
	
	
};

void TemperatureReader::Read(TemperatureItem* temperatureItem)
{
	currentTemperatureItem = temperatureItem;	
	
	for(auto iter = currentTemperatureItem->Channels.begin();
		iter != currentTemperatureItem->Channels.end();
		++iter)
	{
		ReadChannel(currentTemperatureItem->Address, *iter);
	}
}

void TemperatureReader::ReadChannel(char address, char channel)
{
	// config register %1010 1000
	// /RDY = 1, One Conversion, 15 samples per, PGA = X1
	//
	
	// 'mode' = MCP3424 8-bit configuration register
	// see sec. 5.2 Configuration Register, p. 18 of datasheet
	// b7  b6  b5  b4    b3  b2  b1  b0  ----- (bit number)
	// RDY C1  C0  O/C   S1  S0  G1  G0  ----- (bit name)
	// --------------------------------
	// RDY = 0 when ready (or in one-shot, write '1' to start conversion)
	// C1/C0: input channel # 00 = 0, 01 = 1, 10 = 2, 11 = 3
	// O/C: 1 = continuous conversion mode, 0 =  single-shot conversion
	// S1/S0: rate: 00 = 240 Hz (12 b), 01 = 60 Hz (14 b) 10 = 15 Hz (16 b) 11 = 3.75 Hz (18 b)
	// G1/G0: gain: 00 = x1, 01 = x2, 10 = x4, 11 = x8    FullScale: 2.048 V, 1.024, 0.512, 0.256

	// 0001 1100  0x1C is channel 0, continuous, 18-bit, gain x1
	// 0011 1100  0x3C is channel 1, continuous, 18-bit, gain x1
	
	// 0XX0 1100 XX channel, single, 18-bit, 3.75 Hz
	
	char Config;
	
	Wire.beginTransmission(address);
	
	Config = 0x0e; // 0000 1100
	
	Config = Config | (channel << 5); // 0xx0 1100
	
	Wire.write(Config);
	Wire.endTransmission();
	
	//OnReceiveHelper(this);
}

void TemperatureMonitor::Render(Lcd* lcd)
{
	
}