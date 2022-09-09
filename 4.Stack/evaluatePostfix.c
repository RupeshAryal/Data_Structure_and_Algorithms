#include<stdio.h>
#include<stdlib.h>
#include<cstring>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

//lets create a function to push the data into stack
void push(int x) 
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node)); //this will create a new Node 
    if(t == NULL)
        printf("stack overflow \n");
    else
     t->data = x; //insert the value of the node
     t->next = top; //links the node with the current top node of the stack
     top = t; //makes node t the top of the stack
}

//function to pop elements out of a stack
int  pop()
{
    struct Node *t; //create a new node 
    int x = -1;
    if(top == NULL)
        printf("stack underflow \n");
    else
    {
        t = top; //assign new node the structure of the top node of the stack
        top = top->next; //move top to the second node of the stack and make that node the top node
        x = t->data; //assign the data of the previous top to x
        free(t);//delete the temporary node
    }

    return x;
}

int isOperand(char x)
{
    if (x == '+' || x == '*'  || x == '-'  || x == '/' )
        return 0;
    else
        return 1;
}

int eval(char *postfix)
{
    int x2, x1, r = 0;
    int i = 0;

    for(i=0; postfix[i]!=0; i++)
    {
        if(isOperand(postfix[i]))
            push(postfix[i] - '0');
        else
        {
            x2 = pop();
            x1 = pop();

            switch(postfix[i])
            {
                case '+': r = x1 + x2; break;
                case '/': r = x1 / x2; break;
                case '*': r = x1 * x2; break;
                case '-': r = x1 - x2; break;
            }

            push(r);
        }    
    }
    return top->data;
}

int main()
{
    char postfix[] = "234*+82/-";

    printf("%d \n", eval(postfix));

    return 0;
}

