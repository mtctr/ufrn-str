#include <iostream>
#include <pthread.h>
#include "BlackGPIO/BlackGPIO.h"
#include "ADC/Adc.h"
#include <unistd.h>
#include <sys/time.h>     // getpriority(int which, int who)  setpriority(int which, int who, int prio);
#include <sys/resource.h>
#include <math.h>


using namespace BlackLib;

void carga(){
  struct timeval tstart, tend;
  gettimeofday(&tstart, NULL);
  float f = 0.999999;
  float c = 1;
  while(tend.tv_sec - tstart.tv_sec < 1){
    c *= c;
    f = f*f*f*f*f*c;
    f = 1.56;
    f = sin(f)*sin(f)*f*f*f*c;
    gettimeofday(&tend, NULL);
  }
}


int main(int argc, char * argv[]){
  double v0,v1;


  //seta a prioridade do processo pai para 0
  setpriority(PRIO_PROCESS, getpid(), 0);

  ADC adc0(AINx::AIN0);
  ADC adc1(AINx::AIN1);
  BlackGPIO led1(GPIO_30, output);
  BlackGPIO led2(GPIO_60, output);
  led1.setValue(low); //blue
  led2.setValue(low); //red



  int pfilho1, pfilho2, cont;

  pfilho1=fork(); /* criacao do filho 1 */
  pfilho2=fork(); /* criacao do filho 2 */
  cont = 0;
  while(true){
    v0 = adc0.getFloatValue();
    v1 = adc1.getFloatValue();
    std::cout<<"v0 "<<v0<<endl;
    std::cout<<"v1 "<<v1<<endl;

    if(pfilho1==0){/* acoes do filho 1*/
      if(v0>1.0){
        //seta a prioridade do processo filho 1 para 5
        setpriority(PRIO_PROCESS, getpid(), 5);
      }else{
        //seta a prioridade do processo filho 1 para 19
        setpriority(PRIO_PROCESS, getpid(), 19);
      }

      while(cont<50){
        std::cout<<"filho1 "<<getpid()<<endl;
        cont++;
        carga();
        if(cont%2 == 0){
          led1.setValue(high);
        }else{
          led1.setValue(low);
        }
      }
      cont = 0;

    }
    if(pfilho2==0){/* acoes do filho 2*/
      if(v1>1.0){
        //seta a prioridade do processo filho 2 para 5
        setpriority(PRIO_PROCESS, getpid(), 5);
        //std::cout << "valor da prioridade do processo: " << getpriority(PRIO_PROCESS, getpid()) <<endl;
      }else{
        //seta a prioridade do processo filho 1 para 19
        setpriority(PRIO_PROCESS, getpid(), 19);
        //std::cout << "valor da prioridade do processo: " << getpriority(PRIO_PROCESS, getpid()) <<endl;
      }

      while(cont<50){
        std::cout<<"filho2 "<<getpid()<<endl;
        cont++;
        carga();
        if(cont%2 == 0){
          led2.setValue(high);
        }else{
          led2.setValue(low);
        }
      }
      cont = 0;
    }

    sleep(0.5);
  }

  exit(0);
  return 0;
}
