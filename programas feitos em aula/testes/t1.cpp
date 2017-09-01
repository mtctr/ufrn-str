#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int pid, pid1, pid2, pid3, pid4, pid5;
	printf("\nPID pai: %i \n", getpid());	
	pid = fork();

	
	if(pid ==-1){ //erro
		printf("\n estéril");
		exit(-1);
	}
//FILHO 1
	else if (pid == 0){ //filho 1		
		printf("\nPID filho 1: %i \n", getpid());
		
		pid2 = fork();
	

//NETO 1
		if (pid2 == 0){	
			printf("\nPID neto 1 filho 1: %i \n", getpid());
		
			exit(1);
		}
		pid3 = fork();
//NETO 2
		if (pid3 == 0){
			printf("\nPID neto 2 filho 1: %i \n", getpid());
			sleep(5);
			exit(1);
		}				
		sleep(5);			
		exit(1);
	}
	
	pid1 = fork();

//FILHO 2
	 if (pid1 == 0){//filho 2
		printf("\nPID filho 2: %i \n", getpid());
		
		pid4 = fork();	

//NETO 1
		if (pid4 == 0){	
			printf("\nPID neto 1 filho 2: %i \n", getpid());
		
			exit(1);
		}
		pid5 = fork();
//NETO 2
		if (pid5 == 0){
			printf("\nPID neto 2 filho 2: %i \n", getpid());
		
			exit(1);
		}
		sleep(5);	
		exit(1);
	}		
	exit(0);

	printf("\naaaa");
}
