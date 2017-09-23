/**
 * Autor: Tiago Fernandes de Miranda
 * Universidade Federal do Rio Grande do Norte
 */

#include <iostream>
#include <pthread.h>
#include "BlackGPIO/BlackGPIO.h"
#include "ADC/Adc.h"

// Inclua as classes que achar necessario

using namespace BlackLib;

int main(int argc, char * argv[]){
    std::cout << "Example 1 - GPIO (in/out)" << endl;
    BlackGPIO saida(GPIO_20, output);
    BlackGPIO entrada(GPIO_67,input);

    while(true){
      std::string val = entrada.getValue();
      if(val=="1"){
        saida.setValue(high);
        std::cout<<"i'm high"<<endl;
        }
        else{
          saida.setValue(low);
          std::cout<<"i'm low"<<endl;
        }
    }
    return 0;
}
