/*Written by: Aqilah Misuary
Date: 4th June 2020
Final Project for Programming Fundamentals
Compute the average weight for a population of elephant seals read into an array
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, index = 0;
    FILE *fptr;
	int array[1000];
	double avg, sum = 0.0;

    if ((fptr = fopen("/Users/aqilahmisuary/Documents/GitHub/cprograms/seals.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
    }

	//Read values from file, store in array
    while(fscanf(fptr,"%d", &num) != EOF){
		fscanf(fptr,"%d", &num);
		index++;
		array[index] = num;
		sum = sum + array[index]; 
	   // printf("%d\t", num);
		printf("%d\t", array[index]);
	};
	
	printf("\n");	
	//Print total sum
    printf("Total sum of seal weights: %f\n", sum);
	//Calculate average
	avg = sum / index;
	//Print avg 
	printf("Average weight: %f\n", avg);

	fclose(fptr); 
  
    return 0;
}
