/*
	The ADT List
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

//Define a linked list node
typedef struct list {int data; struct list *next;} list;

//Check if list is empty by whether the current pointer at the list is NULL
int is_empty(const list *l){return (l == NULL);}

//Function to create a list
list* create_list(int d)
{
	//malloc allocates the requested memory and returns a pointer to it
	list* head = malloc(sizeof(list));
	head -> data = d;
	head -> next = NULL;
	return head;
}

//To build a list, we add to the front of it
list* add_to_front(int d, list* h)
{
	//Create list
	list* head = create_list(d);
	//Current head will point at next and this new element will the new head
	head -> next = h;
	return head;
}

//Convert array to list (we will have array of data and its size)
list* array_to_list(int d[], int size) 
{
	//Create a list using the first element of the array
	list* head = create_list(d[0]);
	int i;
	//Create until the size of the array (keep updating the head)
	for(i = 1; i < size; i++)
	{
		head = add_to_front(d[i], head);
	}
	return head;
}

void print_list(list *h, char *title)
{
	int count = 0;
	printf("%s\n", title);
	//Stop when the head is NULL
	while (h != NULL)
	{
		count++;
		printf("%d :", h -> data);
		h = h -> next;
		if ((count % 25) == 0)
		{
			printf("\n");
		}
	}
}

//Fill array with random numbers
void fill_array(int array[], int low, int upper, int count)
{
	for (int i = 0; i < count; i++)
	{
		int randNum = (rand() % (upper - low + 1)) + 1;
		array[i] = randNum;
	}
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//Bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

	//Last i elements in place
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
} 

int main()
{
	list list_of_int;
	list* head = NULL;
	int array[100], arraySize;
	time_t t;

	// Initialises random number generator
	srand((unsigned) time(&t));

	//Fill array
	fill_array(array, 0, 100, 100);
	
	//Bubble sort
	arraySize = sizeof(array)/sizeof(array[0]);
	bubbleSort(array, arraySize);

	//Convert array to list
	head = array_to_list(array, 100);

	//Print list
	print_list(head, "100-element list");
	printf("\n\n");
	return 0;
}
