// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa sinal2.cpp
// Sinais sã eventos gerados pelo Unix em resposta a algumas condições, como:
//  erros, violação de memória, instrução ilegal, ...

#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()




void ouch (int sig)
{
	static int i = 0; 
	if (i<2){  
		system("clear");
  	printf("Ah, Ah, Ah-  Eu não morro com : %d \n", sig);
  	printf("Pelo menos, da primeira vez. Tente de novo..\n\n\n");
 		i++;
	}
	else{
		signal(SIGINT, SIG_DFL);
	}
}

int main()
{
	 
	(void) signal(SIGINT, ouch); // SIGINT - Terminal Interrupt

  while(1) {
    printf("Olá, Mundo Cruel! Vou dormir por  1 segundo.\n");
    printf("Tente me matar com Ctrl-C.\n");
    sleep(1);
  }
  // exit(0);
}
