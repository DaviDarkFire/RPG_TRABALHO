#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int a;
	srand(time(NULL));	
	a = rand()%7+1;
	printf("%d\n", a);
	
	
	return 0;
}