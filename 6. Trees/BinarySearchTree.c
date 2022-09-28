#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

struct Node
{
    struct Node *LeftChild;
    int data;
    struct Node *RightChild;
}*root = NULL;

void insert(int value)
{
    struct Node *p, *t, *tail;
    t = root;
    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p -> data = value;
        p -> LeftChild = p->RightChild = NULL;
        root = p;
        return;
    }

    
     while (t!= NULL)
    {
        tail = t;
        if (value > t->data)
            {
               t = t->RightChild;
            }
        else if (value < t->data)
            {
                t = t->LeftChild;
            }
        else
            return;
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = value;
    p->LeftChild = p->RightChild = NULL;

    if (value < tail->data)
    {
        tail->LeftChild = p;
    }

    else
        tail->RightChild = p;
    
}
void sort(struct Node *t) // this is basically inorder traversal
{
    if (t!= NULL)
    {
        sort(t->LeftChild);
        printf("%d ", t->data);
        sort(t->RightChild);
    }    
}

void create(int intArray[]) //this function takes in an array and insert them into the BST until all the elements are inserted
{
    int i = 0;
    while(intArray[i] < SIZE)
    {
        insert(intArray[i]);
        i++;
    }
}

struct Node *Search (int key)
{
    struct Node *t = root;
    while(t != NULL)
    {
        if (key < t->data)
            t = t->LeftChild;
        else if(key > t->data)
            t = t->RightChild;
        else    
            return t; 
    }
    return t;
}

struct Node *RecursiveInsert(struct Node *p, int value)
{
    struct Node *t = NULL;

    if (p==NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node))
        t->data = value;
        t->LeftChild = t->RightChild = NULL;
        return t;
    }
    if (value < p->data)
        p->LeftChild = RecursiveInsert(p->LeftChild, value);
    else if(value > p->data)
        p->RightChild = RecursiveInsert(p->RightChild, value);

     return p;   
}
   
int main()
{
    struct Node *temp;
    int Array[SIZE] = {30,20,10,15,25,40,50,45};

    
    create(Array);
    sort(root);

   printf("%d", root->data);
    
    return 0;
}