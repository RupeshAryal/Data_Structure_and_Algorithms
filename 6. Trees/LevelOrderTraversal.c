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
        printf("enter left child \n");
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node)); //create a left node
            t->data = x; //assign data to left child of the node
            t->LeftChild = t-> RightChild = NULL; //set both children of left node as NULL
            p->LeftChild = t; //assign this current left node as left node of previously dequeued root node
            enqueue(&q, t); //enqueue this left child
        }

        printf("enter right child \n"); //do the same for left child
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

void LevelOrderTraversal(struct Node *p)
{
    struct Queue q;
    printf("%d ", p->data);
    enqueue(&q, p);
    
    while(!isEmpty(q))
    {
        p = dequeue(&q);
        if(p->LeftChild)
        {
            printf("%d ",p->LeftChild->data);
            enqueue(&q,p->LeftChild);
        }

        if(p->RightChild)
        {
            printf("%d ", p->RightChild->data);
            enqueue(&q, p->RightChild);
        }
    }
}

int main()
{
    create();
    LevelOrderTraversal(root);
    return 0;
}