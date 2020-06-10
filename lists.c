/*
	The ADT List
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

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
	printf("%s\n", title);
	//Stop when the head is NULL
	while (h != NULL)
	{
		printf("%d :", h -> data);
		h = h -> next;
	}
}

int main()
{
	list list_of_int;
	list* head = NULL;
	int data[6] = {2, 3, 5, 7, 8, 9};
	//Create a list of 6 elements
	head = array_to_list(data, 6);
	print_list(head, "data[6] made into six-element list");
	printf("\n\n");
	return 0;
}
