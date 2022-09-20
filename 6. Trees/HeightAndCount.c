#include<stdio.h>
#include<stdlib.h>

#include "Queue.h"

struct Node *root = NULL;

void create()
{
    struct Node *p, *t; //create two temporary pointer
    int x; //hold root node data
    struct Queue q;
    CreateQueue(&q, 100); //creat a queue of size 100
    printf("please enter the value of root node");
    scanf("%d", &x);
    
    root = (struct Node *)malloc(sizeof(struct Node)); //create a pointer to root node
    root->data = x; //assign data to root node
    root-> LeftChild = root->RightChild = NULL; //make leftchild and right child Node of root as NULl
    enqueue(&q, root); //enqueue the root node address into the queue

    while(!isEmpty(q)) //while q is not empty
    {
        p = dequeue(&q); //dequeue the address from queue 
        printf("enter left child of %d\n", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node)); //create a left node
            t->data = x; //assign data to left child of the node
            t->LeftChild = t-> RightChild = NULL; //set both children of left node as NULL
            p->LeftChild = t; //assign this current left node as left node of previously dequeued root node
            enqueue(&q, t); //enqueue this left child
        }

        printf("enter right child of %d\n", p->data); //do the same for left child
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->LeftChild = t-> RightChild = NULL;
            p->RightChild = t;
            enqueue(&q, t);
        }
    }

}



int count(struct Node *root)
{
    if(root)
        return count(root -> LeftChild) + count(root->RightChild) + 1;//this will recursively go to left child and at the end when both left and right child are 
    return 0;                                                       //null this they will return 0 + 0 + 1. i.e count the node
}

int height(struct Node *root)
{
    int x = 0, y= 0;
    if (root == NULL)
    {
        return -1;
    }
    x = height(root->LeftChild); //go to left child recursively until you encounter NULL
    y = height(root->RightChild);//then go to right child recursively until you reach NULL

    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int CountLeaf(struct Node *root)
{
    static int count = 0;
    if (root != NULL)
    {
        CountLeaf(root->LeftChild);
        CountLeaf(root->RightChild);
        if(root->LeftChild == NULL && root->RightChild == NULL)
            {
            count++;
            return count;
            }
        else
        {
            return count;
        }
    }
    else
        return 0;
}

int CountInternalVertices(struct Node *root)
{
    static int count = 0;
    if (root != NULL)
    {
        CountInternalVertices(root->LeftChild);
        CountInternalVertices(root->RightChild);
        if(root->LeftChild != NULL || root->RightChild != NULL)
            {
             count++;
             return count;
            }
        else
        {
               return count;
        }
    }
    else
        return 0;
}




int main()
{
    create();
    int nodes =  count(root);
    int leaves = CountLeaf(root);

    printf("%d/n", nodes);
    printf("%d/n", leaves);

    int internal = nodes - leaves;

    printf("%d \n ", internal);



    printf("\n no of internal vertices are %d", CountInternalVertices(root));
    
    return 0;
}