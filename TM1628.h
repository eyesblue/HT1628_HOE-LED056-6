#ifndef TM1628_h
#define TM1628_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class TM1628
{
  public:
	// init
	TM1628(byte _dio_pin, byte _clk_pin, byte _stb_pin);
	
	void begin(boolean active, byte intensity);
	void clear();

	void setNum(uint8_t index, uint8_t num, bool hasDot);

  	void sendData(byte addr, byte data);
  	void sendCommand(byte data);
  	void send(byte data);
    
  	byte _dio_pin;
  	byte _clk_pin;
  	byte _stb_pin;
};

#endif
