/**
* Autor: Tiago Fernandes de Miranda
* Universidade Federal do Rio Grande do Norte
*/

#include <iostream>
#include <pthread.h>
#include "BlackGPIO/BlackGPIO.h"
#include "ADC/Adc.h"
#include <sstream>
#include <unistd.h>
#include <stdlib.h>     /* srand, rand */
#include <sys/time.h>       /* time */
#include <math.h>
using namespace BlackLib;

int main(int argc, char * argv[]){
  double tWait,tReact;
  struct timeval tStart, tEnd;

  //random seed
  std::srand (time(NULL));
  /*
  1: 68,66,69,44,26,46,65
  2: 45,47,60,48,49,117,61
  A1 - 46
  B1 - 26
  C1 - 68
  D1 - 66
  E1 - 44
  F1 - 69
  G1 - 65
  */
  //declaração do display
  BlackGPIO a1 (GPIO_46,output);
  BlackGPIO b1 (GPIO_26,output);
  BlackGPIO c1 (GPIO_68,output);
  BlackGPIO d1 (GPIO_66,output);
  BlackGPIO e1 (GPIO_44,output);
  BlackGPIO f1 (GPIO_69,output);
  BlackGPIO g1 (GPIO_65,output);
  /*
  A2 - 48
  B2 - 60
  C2 - 49
  D2 - 45
  E2 - 47
  F2 - 49
  G2 - 61
  */

  BlackGPIO a2 (GPIO_48,output);
  BlackGPIO b2 (GPIO_60,output);
  BlackGPIO d2 (GPIO_45,output);
  BlackGPIO e2 (GPIO_47,output);
  BlackGPIO f2 (GPIO_49,output);
  BlackGPIO g2 (GPIO_61,output);

  a1.setValue(low);
  b1.setValue(low);
  c1.setValue(low);
  d1.setValue(low);
  e1.setValue(low);
  f1.setValue(low);
  g1.setValue(high);

  a2.setValue(low);
  b2.setValue(low);
  d2.setValue(low);
  e2.setValue(low);
  f2.setValue(low);
  g2.setValue(high);

  BlackGPIO out(GPIO_20,output);
  BlackGPIO in(GPIO_67,input);
  std::cout << "START" << endl;

  while(true){
    std::string val = in.getValue();
    if(val=="0"){
      std::cout << "Botão apertado" << endl;
      tWait = 3 * ((double)std::rand() / (double)RAND_MAX )+1;
      std::cout<<"Tempo de espera: "<< tWait<<endl;
      sleep(tWait);

      gettimeofday(&tStart, NULL);
      out.setValue(high);
      val = in.getValue();
      while(val == "1"){
        val = in.getValue();
      }
      gettimeofday(&tEnd, NULL);

      tReact = (int long) (1000*(tEnd.tv_sec - tStart.tv_sec) + (tEnd.tv_usec - tStart.tv_usec)/1000);
      tReact= round((tReact/1000)*10 + 0.5)/10;
      cout<<"Tempo de reação: "<<tReact<<endl;

      std::string nums = std::to_string(tReact);
      char n1 = nums[0];
      char n2 = nums[2];


      switch (n1){
        case '0':
        a1.setValue(low);
        b1.setValue(low);
        c1.setValue(low);
        d1.setValue(low);
        e1.setValue(low);
        f1.setValue(low);
        g1.setValue(high);
        break;
        case '1':
        a1.setValue(high);
        b1.setValue(low);
        c1.setValue(low);
        d1.setValue(high);
        e1.setValue(high);
        f1.setValue(high);
        g1.setValue(high);
        break;
        case '2':
        a1.setValue(low);
        b1.setValue(low);
        c1.setValue(high);
        d1.setValue(low);
        e1.setValue(low);
        f1.setValue(high);
        g1.setValue(low);
        break;
        case '3':
        a1.setValue(low);
        b1.setValue(low);
        c1.setValue(low);
        d1.setValue(low);
        e1.setValue(high);
        f1.setValue(high);
        g1.setValue(low);
        break;
        case '4':
        a1.setValue(high);
        b1.setValue(low);
        c1.setValue(low);
        d1.setValue(high);
        e1.setValue(high);
        f1.setValue(low);
        g1.setValue(low);
        break;
        case '5':
        a1.setValue(low);
        b1.setValue(high);
        c1.setValue(low);
        d1.setValue(low);
        e1.setValue(high);
        f1.setValue(low);
        g1.setValue(low);
        break;
        case '6':
        a1.setValue(low);
        b1.setValue(high);
        c1.setValue(low);
        d1.setValue(low);
        e1.setValue(low);
        f1.setValue(low);
        g1.setValue(low);
        break;
        case '7':
        a1.setValue(low);
        b1.setValue(low);
        c1.setValue(low);
        d1.setValue(high);
        e1.setValue(high);
        f1.setValue(low);
        g1.setValue(high);
        break;
        case '8':
        a1.setValue(low);
        b1.setValue(low);
        c1.setValue(low);
        d1.setValue(low);
        e1.setValue(low);
        f1.setValue(low);
        g1.setValue(low);
        break;
        case '9':
        a1.setValue(low);
        b1.setValue(low);
        c1.setValue(low);
        d1.setValue(low);
        e1.setValue(high);
        f1.setValue(low);
        g1.setValue(low);
        break;
      }
      switch (n2){
        case '0':
        a2.setValue(low);
        b2.setValue(low);

        d2.setValue(low);
        e2.setValue(low);
        f2.setValue(low);
        g2.setValue(high);
        break;
        case '1':
        a2.setValue(high);
        b2.setValue(low);

        d2.setValue(high);
        e2.setValue(high);
        f2.setValue(high);
        g2.setValue(high);
        break;
        case '2':
        a2.setValue(low);
        b2.setValue(low);

        d2.setValue(low);
        e2.setValue(low);
        f2.setValue(high);
        g2.setValue(low);
        break;
        case '3':
        a2.setValue(low);
        b2.setValue(low);

        d2.setValue(low);
        e2.setValue(high);
        f2.setValue(high);
        g2.setValue(low);
        break;
        case '4':
        a2.setValue(high);
        b2.setValue(low);

        d2.setValue(high);
        e2.setValue(high);
        f2.setValue(low);
        g2.setValue(low);
        break;
        case '5':
        a2.setValue(low);
        b2.setValue(high);

        d2.setValue(low);
        e2.setValue(high);
        f2.setValue(low);
        g2.setValue(low);
        break;
        case '6':
        a2.setValue(low);
        b2.setValue(high);

        d2.setValue(low);
        e2.setValue(low);
        f2.setValue(low);
        g2.setValue(low);
        break;
        case '7':
        a2.setValue(low);
        b2.setValue(low);

        d2.setValue(high);
        e2.setValue(high);
        f2.setValue(low);
        g2.setValue(high);
        break;
        case '8':
        a2.setValue(low);
        b2.setValue(low);

        d2.setValue(low);
        e2.setValue(low);
        f2.setValue(low);
        g2.setValue(low);
        break;
        case '9':
        a2.setValue(low);
        b2.setValue(low);

        d2.setValue(low);
        e2.setValue(high);
        f2.setValue(low);
        g2.setValue(low);
        break;
      }

      val = in.getValue();
      while(val == "0"){
        val = in.getValue();
      }

      out.setValue(low);
    }

  }
  return 0;
}
