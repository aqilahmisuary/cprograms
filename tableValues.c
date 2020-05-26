#include <stdio.h>
#include <math.h>

int main(void)
{
	double interval;
	double i;
	for(i = 0.0; i < 1.0; i+= 0.1)
	{
		interval = i;
		printf("sin(%lf) = %lf cos(%lf) = %lf\n", interval, sin(interval), interval, cos(interval));
	}
	return 0;
}
