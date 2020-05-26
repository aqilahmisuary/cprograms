#include <stdio.h>
#include <math.h> //Has sin(), abs() and fabs()

int main(void)
{
	double interval;
 	int i;
	for(i = 0; i < 30; i++)
	{
		interval = i/10.0;
		//Changed spacing from tab to newline for better readability.
		printf("sin(%lf) = %lf\n", interval, fabs(sin(interval))); //Change from abs() to fabs()
	}
	
	printf("\n+++++++\n");
	return 0;
}	

