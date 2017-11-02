#include <iostream>
#include <pthread.h>
#include "BlackGPIO/BlackGPIO.h"
#include "ADC/Adc.h"
#include <unistd.h>
#include <sys/time.h>     // getpriority(int which, int who)  setpriority(int which, int who, int prio);
#include <sys/resource.h>
#include <math.h>
#include <errno.h>

/*
A1 - 47
B1 - 27
C1 - 49
D1 - 48
E1 - 61
F1 - 46
G1 - 65

A2 - 26
B2 - 44
C2 - 68
D2 - 67
E2 - 69
F2 - 45
G2 - 66
*/

using namespace BlackLib;

//inicialização dos pinos
ADC adc1(AINx::AIN0);
ADC adc2(AINx::AIN1);
BlackGPIO bt(GPIO_60, input);

BlackGPIO A1(GPIO_47, output);
BlackGPIO B1(GPIO_27, output);
BlackGPIO C1(GPIO_49, output);
BlackGPIO D1(GPIO_48, output);
BlackGPIO E1(GPIO_61, output);
BlackGPIO F1(GPIO_46, output);
BlackGPIO G1(GPIO_65, output);

BlackGPIO A2(GPIO_26, output);
BlackGPIO B2(GPIO_44, output);
BlackGPIO C2(GPIO_68, output);
BlackGPIO D2(GPIO_67, output);
BlackGPIO E2(GPIO_69, output);
BlackGPIO F2(GPIO_45, output);
BlackGPIO G2(GPIO_66, output);

pthread_mutex_t trilho3_mutex = PTHREAD_MUTEX_INITIALIZER;

float v1;
float v2;

//inicialização das funções
void disp1(int n);
void disp2(int n);
void L( int numTrem, int trilho);
void* thread_function1(void* data);
void* thread_function2(void* data);

int main(int argc, char * argv[]){
  srand(time(NULL));

  pthread_t thread1, thread2;
  pthread_mutex_init(&trilho3_mutex, NULL);

  pthread_create(&thread1, NULL, thread_function1, NULL);
  pthread_create(&thread2, NULL, thread_function2, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}

void L( int numTrem, int trilho){
  if(numTrem == 1){
    disp1(trilho);
    printf("%s%d\n", "trem 1 trilho,", trilho);
    printf("velocidade = %f\n", 1/(v1+0.5)+1);
    sleep(1/(v1+.5)+1);
  }else{
    disp2(trilho);
    printf("%s%d\n", "trem 2 trilho,", trilho);
    printf("velocidade = %f\n", 1/(v2+0.5)+1);
    sleep(1/(v2+.5)+1);
  }
}

void* thread_function1(void* data){
    int num = (int) data;
    while(1){
        v1 = adc1.getFloatValue();
        L(1,1);
        v1 = adc1.getFloatValue();
        L(1,2);
        v1 = adc1.getFloatValue();
        pthread_mutex_lock(&trilho3_mutex);
        L(1,3);
        pthread_mutex_unlock(&trilho3_mutex);
        v1 = adc1.getFloatValue();
        L(1,4);
    }
}

void* thread_function2(void* data){
    int num = (int) data;
    while(1){
      v2 = adc2.getFloatValue();
      L(2,5);
      v2 = adc2.getFloatValue();
      L(2,6);
      v2 = adc2.getFloatValue();
      L(2,7);
      v2 = adc2.getFloatValue();
      pthread_mutex_lock(&trilho3_mutex);
      L(2,3);
      pthread_mutex_unlock(&trilho3_mutex);
    }
}


void disp1(int n){
  char nc = std::to_string(n)[0];
  switch (nc){
    case '0':
    A1.setValue(low);    B1.setValue(low);    C1.setValue(low);    D1.setValue(low);
    E1.setValue(low);    F1.setValue(low);    G1.setValue(high);
    break;

    case '1':
    A1.setValue(high);    B1.setValue(low);    C1.setValue(low);    D1.setValue(high);
    E1.setValue(high);    F1.setValue(high);    G1.setValue(high);
    break;

    case '2':
    A1.setValue(low);    B1.setValue(low);    C1.setValue(high);    D1.setValue(low);
    E1.setValue(low);    F1.setValue(high);    G1.setValue(low);
    break;
    case '3':

    A1.setValue(low);    B1.setValue(low);    C1.setValue(low);    D1.setValue(low);
    E1.setValue(high);    F1.setValue(high);    G1.setValue(low);
    break;

    case '4':
    A1.setValue(high);    B1.setValue(low);    C1.setValue(low);    D1.setValue(high);
    E1.setValue(high);    F1.setValue(low);    G1.setValue(low);
    break;

    case '5':
    A1.setValue(low);    B1.setValue(high);    C1.setValue(low);    D1.setValue(low);
    E1.setValue(high);    F1.setValue(low);    G1.setValue(low);
    break;

    case '6':
    A1.setValue(low);    B1.setValue(high);    C1.setValue(low);    D1.setValue(low);
    E1.setValue(low);    F1.setValue(low);    G1.setValue(low);
    break;

    case '7':
    A1.setValue(low);    B1.setValue(low);    C1.setValue(low);    D1.setValue(high);
    E1.setValue(high);    F1.setValue(low);    G1.setValue(high);
    break;

    case '8':
    A1.setValue(low);    B1.setValue(low);    C1.setValue(low);    D1.setValue(low);
    E1.setValue(low);    F1.setValue(low);    G1.setValue(low);
    break;

    case '9':
    A1.setValue(low);    B1.setValue(low);    C1.setValue(low);    D1.setValue(low);
    E1.setValue(high);    F1.setValue(low);    G1.setValue(low);
    break;
  }
}

void disp2(int n){
char nc = std::to_string(n)[0];
  switch (nc){
    case '0':
    A2.setValue(low);    B2.setValue(low);    C2.setValue(low);    D2.setValue(low);
    E2.setValue(low);    F2.setValue(low);    G2.setValue(high);
    break;
    case '1':
    A2.setValue(high);    B2.setValue(low);    C2.setValue(low);    D2.setValue(high);
    E2.setValue(high);    F2.setValue(high);    G2.setValue(high);
    break;

    case '2':
    A2.setValue(low);    B2.setValue(low);    C2.setValue(high);    D2.setValue(low);
    E2.setValue(low);    F2.setValue(high);    G2.setValue(low);
    break;

    case '3':
    A2.setValue(low);    B2.setValue(low);    C2.setValue(low);    D2.setValue(low);
    E2.setValue(high);    F2.setValue(high);    G2.setValue(low);
    break;

    case '4':
    A2.setValue(high);    B2.setValue(low);    C2.setValue(low);    D2.setValue(high);
    E2.setValue(high);    F2.setValue(low);    G2.setValue(low);
    break;

    case '5':
    A2.setValue(low);    B2.setValue(high);    C2.setValue(low);    D2.setValue(low);
    E2.setValue(high);    F2.setValue(low);    G2.setValue(low);
    break;

    case '6':
    A2.setValue(low);    B2.setValue(high);    C2.setValue(low);    D2.setValue(low);
    E2.setValue(low);    F2.setValue(low);    G2.setValue(low);
    break;

    case '7':
    A2.setValue(low);    B2.setValue(low);    C2.setValue(low);    D2.setValue(high);
    E2.setValue(high);    F2.setValue(low);    G2.setValue(high);
    break;

    case '8':
    A2.setValue(low);    B2.setValue(low);    C2.setValue(low);    D2.setValue(low);
    E2.setValue(low);    F2.setValue(low);    G2.setValue(low);
    break;

    case '9':
    A2.setValue(low);    B2.setValue(low);    C2.setValue(low);    D2.setValue(low);
    E2.setValue(high);    F2.setValue(low);    G2.setValue(low);
    break;
  }
}
