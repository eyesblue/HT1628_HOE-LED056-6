
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include<TM1628.h>

uint8_t _numSeg[10] = {B00111111, B00000110, B01011011, B01001111, B01100110,
                       B01101101, B01111101, B00000111, B01111111, B01101111
                      };

TM1628::TM1628(byte _dio_pin, byte _clk_pin, byte _stb_pin) {
  this->_dio_pin = _dio_pin;
  this->_clk_pin = _clk_pin;
  this->_stb_pin = _stb_pin;

  pinMode(_dio_pin, OUTPUT);
  pinMode(_clk_pin, OUTPUT);
  pinMode(_stb_pin, OUTPUT);

  digitalWrite(_stb_pin, HIGH);
  digitalWrite(_clk_pin, HIGH);

  sendCommand(0x40);
  sendCommand(0x80);

  digitalWrite(_stb_pin, LOW);
  send(0xC0);
  clear();
  digitalWrite(_stb_pin, HIGH);
}

void TM1628::begin(boolean active = true, byte intensity = 1) {
  sendCommand(0x80 | (active ? 8 : 0) | min(7, intensity));
}

void TM1628::setNum(uint8_t index, uint8_t num, bool isShowDot) {
	byte addr=index*2;
	uint8_t data=_numSeg[num];
	if(isShowDot)data+=128;
	sendData(addr, data);
}

void TM1628::clear() {
  for (int i=0; i<=12; i+=2)
    sendData(i, 0x00);
}

/*********** mid level  **********/
void TM1628::sendData(byte addr, byte data) {
  sendCommand(0x44);
  digitalWrite(_stb_pin, LOW);
  send(0xC0 | addr);
  send(data);
  digitalWrite(_stb_pin, HIGH);
}

void TM1628::sendCommand(byte data) {
  digitalWrite(_stb_pin, LOW);
  send(data);
  digitalWrite(_stb_pin, HIGH);
}

/************ low level **********/
void TM1628::send(byte data) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(_clk_pin, LOW);
    digitalWrite(_dio_pin, data & 1 ? HIGH : LOW);
    data >>= 1;
    digitalWrite(_clk_pin, HIGH);
  }
}
