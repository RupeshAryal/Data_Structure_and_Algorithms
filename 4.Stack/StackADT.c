
#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st)
{
    printf("enter the size of stack");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size*sizeof(int));
}

int isEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st)
{
    return (st.top == st.size - 1);
}

void Display(struct Stack st)
{
    for(int i = st.top; i >= 0; i--)
        printf("%d \n", st.S[i]);
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if (isFull(*st) == 1)
    {
        printf("stack overflow \n");
    }
    else
    {
    st->top++;
    st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x;
    if(isEmpty(*st)==1)
    {
        printf("stack empty");
    }
    else
         x = st->S[st->top--];
    return x;
}

int main()
{
    struct Stack s;
    Create(&s);
    push(&s, 5);
    push(&s, 14);s
    push(&s, 13);
    push(&s, 12);
    push(&s, 101);
    push(&s, 10);
    Display(s);

   pop(&s);
   pop(&s);
   pop(&s);
   pop(&s);
   pop(&s);
   pop(&s);




    return 0;
}