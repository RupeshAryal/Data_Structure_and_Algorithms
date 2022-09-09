#include<stdio.h>
#include<stdlib.h>
#include<cstring>

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

//lets create a function to push the data into stack
void push(char x) 
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
char pop()
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


//function to display the elements of the stack by traversing the entire linked list
void Display()
{
    struct Node *t;
    t = top;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t = t->next;
    }
    printf(" \n");
}


//function to assign precedence of elements

int precedence(char x)
{
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

//another function to check whether the given element is operator or operand

int isOperand(char x)
{
    if (x == '+' || x == '*'  || x == '-'  || x == '/' )
        return 0;
    else
        return 1;
}

//we are going to take a expression and the read it character wise until we reach null character

//if the character is an operator and we have the stack empty we push the character to the stack
//if stack is not empty  we check the precendence of the top element of the stack
//if the precendence of the character is higher than the precedence of the element of the topn of the stack
//we push it to the stack 
//if the precendence is lower, we pop the elements and put them in a postfix expression
//then we push the character to the top

//if the character is an operand we push it to the postfix expression


char * ToPostfix(char *infix) //return a string of character and takes a pointer to the first element of a string
{
    int i=0, j = 0;
     int len = strlen(infix); //assign the length of infix expression
    char *postfix = (char *)malloc((len + 2) * sizeof(char)); //create a memory in heap to store postfix expression, len + 2 is because 
                                                              //we want to store the null character as well
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++]; //assign the jth value of postfix expression the ith value of infix expression and increment both the pointers
        else
        {
            if(precedence(infix[i]) > precedence(top -> data))
            {
                push(infix[i++]); //push the operator into the stack and move to the next character
            }
            else
                postfix[j++] = pop(); //else pop and append to the postfix expression
        }
    }
    while(top!=NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
    
}

int main()
{
    char expression[] = "a+b*c-d/e";
    push (' ');
    char *postfix = ToPostfix(expression);
    printf("%s \n", postfix);
    return 0;
}