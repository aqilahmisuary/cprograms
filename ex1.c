/*
	Not all real numbers are machine-representable.
	There are too many of them. Thus, the numbers
	that are available on a machine have a "graininess"
	to them.
*/

#include <stdio.h>

int main(void)
{
	double x = 123.45123451234512345;
	double y = 123.451234512345123000; //last two digits zero

	printf("%.17f\n%.18f\n", x, y);
}
