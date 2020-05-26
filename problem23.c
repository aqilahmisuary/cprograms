#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NCALLS 1000000000 //Number of fct calls
#define NCOLS 8 //number of columns
#define NLINES 3 //number of lines

int main(void)
{
	int i, val;
	long begin, diff, end;

	begin = time(NULL); //Returns time since Epoch (00:00:00 UTC, Jan 1, 1970)
	srand(time(NULL)); //Set Seed for rand() function
	printf("\nTIMING TEST: %d calls to rand()\n\n", NCALLS);
	for(i = 1; i <= NCALLS; ++i)
	{
		val = rand();
		if(i <= NCOLS * NLINES)
		{
			printf("%7d  ", val);
			if(i % NCOLS == 0)
				putchar('\n');
		}
		else if(i == NCOLS * NLINES + 1)
			printf("%7s\n\n","......");
	}
		end = time(NULL);
		diff = end - begin;
		printf("%s%ld\n%s%ld\n%s%ld\n%s%.10f\n\n",
			"	         end time: ", end,
			"	       begin time: ", begin,
			"       	elapsted time: ", diff,
			"      time for each call: ", (double) diff/NCALLS);
		return 0;
}


