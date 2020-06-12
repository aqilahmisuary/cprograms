/*
    Binary Tree
*/

#include <stdio.h>
#include <stdlib.h>

//Create struct binary tree
typedef struct binaryTree {int value; struct binaryTree *left; struct binaryTree *right;} Binarytree;

//Insert elements in binary tree
void insert(Binarytree **t, int *a, int index, int n)
{
    if (index < n) {
        *t = malloc(sizeof(**t));

        (*t)->value = a[index];
        (*t)->left = NULL;
        (*t)->right = NULL;

        insert(&(*t)->left, a, 2 * index + 1, n);
        insert(&(*t)->right, a, 2 * index + 2, n);
    }
}

//Print binary tree
void printBinaryTree(Binarytree *t, int level)
{
    if (t) {
        printBinaryTree(t->left, level + 1);
        printf("%*s->%d\n", 4*level, "", t->value);
        printBinaryTree(t->right, level + 1);
    }
}

int main()
{

  FILE *fp = fopen("integer.txt", "r");
  int array[50];
  int i = 0, rvalue;

  //Check if there is error opening file
  if(fp == NULL)
  {
    printf("Opening File Error!\n");
  }

  //Populate array
  while(i < 100 && (rvalue = fscanf(fp, "%d", &array[i++])) == 1) ;

  //Check if there are any error indicators
  if(rvalue == EOF)
  {
    if(ferror(fp))
    {
        //Clear any error indicators
        clearerr(fp);
    }
  }

  int myIndex = array[0];
  int myArray[myIndex];

  printf("The array is size %d and the values are:\n", myIndex);

  //Print out arrays
  for(int count = 0; count < i -2; count++)
  {
    myArray[count] = array[count+1];
    printf("\n%d\n",myArray[count]);
  }

  //Print out the binary tree
  printf("\nThe binary tree: \n\n");
  Binarytree *t;
  insert(&t, myArray, 0, myIndex);
  printBinaryTree(t, 0);

  //Close file
  fclose(fp);

  return 0;
}
