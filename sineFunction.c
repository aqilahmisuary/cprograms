#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, value;
	printf("Enter value:");
	scanf("%lf", &x);
	value = sin(x);
	printf("sin(%lf) is %lf", x, value);	
	return 0;
}
