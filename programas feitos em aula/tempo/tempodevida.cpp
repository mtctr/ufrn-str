#include <iostream>
#include <time.h>

using namespace std;

int main(){


struct tm tbirth;
int dia, mes, ano, hora, min, sec;
// variável para armazenar o tempo em segundos
time_t  tnow, difsec,tb;
tnow = time(NULL);
// armazenar o tempo


cout<<"Insira a sua data de nascimento"<<endl;
cin>>dia;
cin>>mes;
cin>>ano;
cin>>hora;
cin>>min;
cin>>sec;

tbirth.tm_mday = dia; tbirth.tm_mon = mes-1; tbirth.tm_year = ano-1900;
tbirth.tm_hour = hora; tbirth.tm_min = min; tbirth.tm_sec = sec;

tb = mktime(&tbirth);

difsec = difftime(tnow, tb);



cout<<difsec<<endl;




}
