#include<stdio.h>
#include<stdlib.h>

//lets use linked list for it.

struct Node
{
    char data;
    struct Node *next;
}*top = NULL;


void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    
    if(t == NULL)
    {
        printf("stack is fulll");
    }
    else
    {
        t->data = x;
        t->next = top;
        top= t;
    }
}

char pop()
{
    char x = -1;
    struct Node *p;

    if(top == NULL)
    {
        printf("stack is empty \n");
    }
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}


int isMatching(char *exp)
{
    int i = 0;
    char x = -1;
   
    for(i = 0; exp[i]!='\0';i++)
    {

        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
       else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']' )
       {
           if(top == NULL)
               return 0;
            x= pop();
            if(exp[i] == ')' && x != '(')
                return 0;
            
            if(exp[i] == '}' && x!= '{')
                return 0;
            
            if(exp[i] == ']' && x != '[')
                return 0;       
       }

    }
    if(top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    char exp[100] = "[{}]";
    printf("%d ",isMatching(exp));
    return 0;
}