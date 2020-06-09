#include <stdio.h>

//Declare enum and struct type
typedef enum month {January, February, March, April, May, June, July, August, September, October, November, December} month;
typedef struct date {month m; int d;} date;

int printDate(enum month m, int d)
{
	printf("\nDate: ");
	switch(m){
	case January: printf("January %d \n", d); break;
	case February: printf("February %d \n", d); break;
	case March: printf("March %d \n", d); break;
	case April: printf("April %d \n", d); break;
	case May: printf("May %d \n", d); break;
 	case June: printf("June %d \n", d); break;
	case July: printf("July %d \n", d); break;
 	case August: printf("August %d \n", d); break;
	case September: printf("September %d \n", d); break ;
	case October: printf("October %d \n", d); break;
	case November: printf("November %d \n", d); break;
	case December: printf("December %d \n", d); break;
	default: printf("%d is an error", m); break;
	}
	return 0;
}

//Calculate next day
int nextDay(enum month m, int d)
{
	//Find the exception months
	if (d == 31 || d == 28 || d == 30)
	{
		if (m == February)
		{
			return d = 1;
			
		} else if (m == April || m == June || m == September || m == November)
		{
			return d = 1;

		} else if (m == January || m == March || m == May || m == July || m == August || m == October || m == December )
		{
			return d = 1;
		}
		
		return (d + 1);

	}	
	return (d + 1);
}

int main ()
{
	//Declare variables
	int tomorrow, whichMonth;

	//Declare date
	struct date currentDate;
	//Dates can be changed here
	currentDate.m = October;
	currentDate.d = 31; 
	
	//Print out current date
	printDate(currentDate.m, currentDate.d);

	//Check tomorrow's date
	tomorrow = nextDay(currentDate.m, currentDate.d);
	if (tomorrow == 1)
	{
		whichMonth = (currentDate.m + 1) % 12;
	} 

	//Print out tomorrow's date
	printf("The next day will be...");
	printDate(whichMonth, tomorrow);

	return 0;
}
