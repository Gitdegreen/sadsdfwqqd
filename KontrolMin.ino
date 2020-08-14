#include "KontrolMin.h"
#include <MemoryFree.h>

KontrolMin kontrol = KontrolMin();
void setup(){
  Serial.begin(115200);
  delay(2000);
  Serial.println();
  Serial.println(F("#####INIT#####"));
  printMemory();
}

void loop(){
  if(Serial.available()){
    kontrol.update(Serial.read());
  }
  kontrol.addListener("lol",test);
}

void test(){
  printMemory();
}
void printMemory(){//FUNCION QUE IMPRIME POR SERIAL LA MEMORIA DISPONIBLE
  Serial.print(F("> MEM FREE: "));
  Serial.print(freeMemory(), DEC);
  Serial.print(", ");
  float percent = freeMemory();
  percent = percent*100/32000;
  Serial.print(percent,2);
  Serial.println("%");
}
