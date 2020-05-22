/* C for Everyone
   Homage to K&R
   Conversion of Fahrenheit to Celcius
   
   C = (F - 32)/1.8
   Sally Coder
*/
#include <stdio.h>
int main(void)
{
	double fahrenheit, celcius;

	printf("Please enter fahrenheit as an integer:");
	scanf("%lf", &fahrenheit);
	celcius = (fahrenheit - 32)/1.8; //note conversion
	printf("\n %lf fahrenheit is %lf celcius.\n",fahrenheit, celcius);
	return 0;
}
