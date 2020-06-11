/*
	Use of FILE I/O
*/

#include <stdio.h>

#define MAX_INT 20

//Function to read the data from file
void read_data(FILE *ptr, int d[], int *size)
{
	*size = 0;
	while(fscanf(ptr, "%d",&d[*size]) == 1)
		(*size)++;
}

//Function to print the data
void print_data(int d[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d\t", d[i]);
		if ((i+ 1) % 10 == 0) printf("\n");
	}
}

//Print array to file
void print_file(FILE *ptr, int d[], int size)
{
	int i=0;
	for(i = 0; i < size; i++)
	{
		fprintf(ptr,"%d ", d[i]);
		if ((i+ 1) % 10 == 0) printf("\n");
	}
}

//Calculate the average
double average(int d[], int size)
{
	int i;
	double avg = 0.0;
	
	for(i = 0; i < size; i++)
		avg += d[i];
	return(avg/size);	
}

//Find the max value in the array
int findMax(int d[], int size)
{
	int j;
	int maximum = d[0];

	for(j = 0; j < size; j++)
	{
		if(d[j] > maximum)
		{
			maximum = d[j];
			
		}
	}
	
	return maximum;
}

int main()
{
	int i, sz = MAX_INT;
	FILE *ifp;
	FILE *fp;
	int data[MAX_INT] = {100, 0};

	//Read file
	ifp = fopen("myInt.txt", "r");
	read_data(ifp, data, &sz);

	//Print to output file
	fp = fopen("answer-hw3", "w");
	print_file(fp, data, sz);

	//Print out the integers
	printf("\nIntegers are: %d \n\n", sz);
	print_data(data, sz);

	//Print Max and Average
	printf("\n\nMaximum is %d\n", findMax(data, sz));
	printf("\nAverage score was %10f", average(data, sz));
	printf("\n\n");

	//Close files
	fclose(ifp);
	fclose(fp);

	return 0;
}
