#include <iostream>
#include <pthread.h>
#include "BlackGPIO/BlackGPIO.h"
#include "ADC/Adc.h"
#include <unistd.h>

// Inclua as classes que achar necessario

using namespace BlackLib;

int main(int argc, char * argv[]){
  int v0,v1;

  ADC adc0(AINx::AIN0);
  ADC adc1(AINx::AIN1);
  BlackGPIO blue(GPIO_30, output);
  BlackGPIO red(GPIO_60, output);
  blue.setValue(low);
  red.setValue(low);

  while(true){
  v0 = adc0.getPercentValue();
  v1 = adc1.getPercentValue();
  std::cout<<v0<<endl;
  std::cout<<v1<<endl;

  if(v0 > v1){
    blue.setValue(high);
    red.setValue(low);
  }else{
    blue.setValue(low);
    red.setValue(high);
  }

  sleep(1);
  }
  return 0;
}
