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
void print(Binarytree *t, int level)
{
    if (t) {
        print(t->left, level + 1);
        printf("%*s->%d\n", 4*level, "", t->value);
        print(t->right, level + 1);
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
  int myArray[myIndex], max;
  double avg = 0;

  printf("The array is size %d and has these values :\n", myIndex);
  for(int j = 0; j < i -2; j++)
  {
    myArray[j] = array[j+1];
    printf("%d ",myArray[j]);
  }

  printf("\nThe binary tree: \n");
    Binarytree *t;
    insert(&t, myArray, 0, myIndex);
    print(t, 0);

    //Close file
    fclose(fp);

    return 0;
}
