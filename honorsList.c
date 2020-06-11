#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

/* a node of the doubly linked list */
struct Node { 
	int data; 
	struct Node* next; 
	struct Node* prev; 
}; 

/* Function to delete a node in a Doubly Linked List. 
head_ref --> pointer to head node pointer. 
del --> pointer to node to be deleted. */
void deleteNode(struct Node** head_ref, struct Node* del) 
{ 
	/* base case */
	if (*head_ref == NULL || del == NULL) 
		return; 

	/* If node to be deleted is head node */
	if (*head_ref == del) 
		*head_ref = del->next; 

	/* Change next only if node to be deleted is NOT the last node */
	if (del->next != NULL) 
		del->next->prev = del->prev; 

	/* Change prev only if node to be deleted is NOT the first node */
	if (del->prev != NULL) 
		del->prev->next = del->next; 

	/* Finally, free the memory occupied by del*/
	free(del); 
	return; 
} 

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* since we are adding at the beginning, 
	prev is always NULL */
	new_node->prev = NULL; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* change prev of head node to new node */
	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
}

// function to remove duplicates from 
// an unsorted doubly linked list 
void removeDuplicates(struct Node** head_ref) 
{ 
    // if DLL is empty or if it contains only 
    // a single node 
    if ((*head_ref) == NULL ||  
        (*head_ref)->next == NULL) 
        return; 
  
    struct Node* ptr1, *ptr2; 
  
    // pick elements one by one 
    for (ptr1 = *head_ref; ptr1 != NULL; ptr1 = ptr1->next) { 
        ptr2 = ptr1->next; 
  
        // Compare the picked element with the 
        // rest of the elements 
        while (ptr2 != NULL) { 
  
            // if duplicate, then delete it 
            if (ptr1->data == ptr2->data) { 
  
                // store pointer to the node next to 'ptr2' 
                struct Node* next = ptr2->next; 
  
                // delete node pointed to by 'ptr2' 
                deleteNode(head_ref, ptr2); 
  
                // update 'ptr2' 
                ptr2 = next; 
            } 
  
            // else simply move to the next node 
            else
                ptr2 = ptr2->next; 
        } 
    } 
}  

/* Function to print nodes in a given doubly linked list 
This function is same as printList() of singly linked list */
void printList(struct Node* node) 
{ 
	while (node != NULL) { 
		printf("%d ", node->data); 
		node = node->next; 
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

/* Driver program to test above functions*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
	time_t t;
	int array[200], arraySize;

	//Initialise random number generator
	srand((unsigned) time(&t));
	
	//Fill array
	fill_array(array, 0, 200, 200);

	//Fill list
	for (int j; j < 200; j++)
	{
		push(&head, array[j]);
	}

	/* Let us create the doubly linked list 10<->8<->4<->2 */
	
	/*push(&head, 2); 
	push(&head, 4); 
	push(&head, 8); 
	push(&head, 10); 
	*/

	printf("\n Original Linked list \n "); 
	printList(head); 
	
	removeDuplicates(&head);
	printf("\n\n After removing duplicates \n");
	printList(head);	
/*	
	// delete nodes from the doubly linked list 
	deleteNode(&head, head); // delete first node
	deleteNode(&head, head->next); // delete middle node
	deleteNode(&head, head->next); // delete last node

	// Modified linked list will be NULL<-8->NULL 
	printf("\n Modified Linked list "); 
	printList(head); 
*/
	getchar(); 
} 

