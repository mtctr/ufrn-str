#define MULTICAST_ADDR "225.0.0.37"

#include <iostream>
#include <pthread.h>
#include "BlackGPIO/BlackGPIO.h"
#include "ADC/Adc.h"
#include <unistd.h>
#include <sys/time.h>     // getpriority(int which, int who)  setpriority(int which, int who, int prio);
#include <sys/resource.h>
#include <math.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>

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


float v1;
float v2;
std::string val = bt.getValue();
pthread_t snd_thread, rcv_thread;

//inicialização das funções
void* snd_function(void* data);
void* rcv_function(void* data);
void disp1(int n);
void disp2(int n);

int main(int argc, char * argv[]){

  disp1(0);
  disp2(0);

	pthread_create(&snd_thread, NULL, snd_function, NULL);
  pthread_create(&rcv_thread, NULL, rcv_function, NULL);

  pthread_join(snd_thread, NULL);
  pthread_join(rcv_thread, NULL);

  return 0;
}

void* snd_function(void* data){

  struct sockaddr_in addr;
  int sockfd;
  int len;
  float floatArray[2];
  unsigned short port_snd = 9702;

  /* create what looks like an ordinary UDP socket */
  sockfd=socket(AF_INET,SOCK_DGRAM,0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  /* set up destination address */
  memset(&addr,0,sizeof(addr));
  addr.sin_family=AF_INET;
  addr.sin_addr.s_addr=inet_addr(MULTICAST_ADDR);
  addr.sin_port=htons(port_snd);

  len = sizeof(addr);

  while(true){
    floatArray[0] = adc1.getPercentValue()/100;
    floatArray[1] = adc2.getPercentValue()/100;
    sendto(sockfd, &floatArray,sizeof(floatArray),0,(struct sockaddr *) &addr, len);
    printf("valores enviados: %f; %f\n", floatArray[0], floatArray[1]);
    sleep(1);
  }
}

void* rcv_function(void* data){
  bool rcv_data[8];
  //string bin;

  int srv_sockfd;
  size_t srv_len;
  socklen_t client_len;
  struct sockaddr_in srv_addr;
  struct sockaddr_in client_addr;
  unsigned short port_rcv = 9802;
  struct ip_mreq mreq;

  srv_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (srv_sockfd < 0) {
    perror("socket");
    exit(1);
  }

  unlink("server_socket");
  memset(&srv_addr, 0, sizeof(srv_addr));


  srv_addr.sin_family = AF_INET;
  srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  srv_addr.sin_port = htons(port_rcv);

  srv_len = sizeof(srv_addr);

  if(bind(srv_sockfd, (struct sockaddr *) &srv_addr, srv_len) > 0){
    perror("Bind error");
    exit(1);
  }

  mreq.imr_multiaddr.s_addr=inet_addr(MULTICAST_ADDR);
  mreq.imr_interface.s_addr=htonl(INADDR_ANY);
  if (setsockopt(srv_sockfd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq)) < 0) {
    perror("setsockopt");
    exit(1);
	}
  client_len = sizeof(client_addr);

  while (true){

    printf("Servidor esperando na porta %d ...\n", port_rcv);


    if(recvfrom(srv_sockfd, &rcv_data, sizeof(rcv_data), 0,
    (struct sockaddr*) &client_addr, &client_len) < 0 ) {
      perror(" erro no RECVFROM( )");
      exit(1);
    } 
    struct in_addr ipAddr = client_addr.sin_addr;
    char str[INET_ADDRSTRLEN];
    inet_ntop( AF_INET, &ipAddr, str, INET_ADDRSTRLEN);
    printf("oi");

    printf("Valor recebido na porta %d do IP %s foi: %d:%d:%d:%d:%d:%d:%d:%d\n", port_rcv, str, rcv_data[0],rcv_data[1],rcv_data[2],rcv_data[3],rcv_data[4],rcv_data[5],rcv_data[6],rcv_data[7]);	
    printf("oi2");
   
 if(rcv_data[0]){
      A1.setValue(low);
    }else{
      A1.setValue(high);
    }

    if(rcv_data[1]){
      B1.setValue(low);
    }else{
      B1.setValue(high);
    }

    if(rcv_data[2]){
      C1.setValue(low);
    }else{
      C1.setValue(high);
    }

    if(rcv_data[3]){
      D1.setValue(low);
    }else{
      D1.setValue(high);
    }

    if(rcv_data[4]){
      E1.setValue(low);
    }else{
      E1.setValue(high);
    }

    if(rcv_data[5]){
      F1.setValue(low);
    }else{
      F1.setValue(high);
    }

    if(rcv_data[6]){
      G1.setValue(low);
    }else{
      G1.setValue(high);
    }

    if(rcv_data[7]){
      A2.setValue(low);
    }else{
      A2.setValue(high);
    }

    sleep(1);
  }
}



//display 1
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
//display 2
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
