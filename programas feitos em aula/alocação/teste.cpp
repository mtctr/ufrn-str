#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(){
	cpu_set_t  mask;
	CPU_ZERO(&mask);
	CPU_SET(1, &mask);
	sched_setaffinity(0, sizeof(mask), &mask);
	CPU_SET(0, &mask);
	sched_setaffinity(0, sizeof(mask), &mask);
	while(1);
}
