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
