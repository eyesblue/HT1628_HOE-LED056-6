
The project provide a arduino library for HOE-LED056-6, I bought it from China.
the library is very light, it just provide clear() and setNum() function, it support
well for deficient device like ATTINY85 or similar Micro chip.

The library is modify from Vasyl Yudin's library(https://github.com/BlockThor/TM1628).

Example code:
---

#include "TM1628.h"

TM1628 ledDisp(10, 11, 12); // dio, clk, stb

void setup(){
ledDisp.begin(true, 2);
}

void loop(){
for (int j = 0; j < 10; j++) {
ledDisp.setNum(0, j, (j%2==1)); // index, num, isShowDot
ledDisp.setNum(1, j, (j%2==0));
ledDisp.setNum(2, j, (j%2==1));
ledDisp.setNum(3, j, (j%2==0));
ledDisp.setNum(4, j, (j%2==1));
ledDisp.setNum(5, j, (j%2==0));
delay(1000);
}

ledDisp.clear();
delay(1000);
}

