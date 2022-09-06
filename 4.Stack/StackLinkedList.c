
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;


void Push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("stack overflow");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int x = -1;
    struct Node *t;
    if(top == NULL)
        printf("stack underflow");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *t;
    t = top;
    while(t!=NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}




int main()
{
    char *exp = "((a+b))";
    printf("%d ",isMatching(&exp));
    return 0;
}