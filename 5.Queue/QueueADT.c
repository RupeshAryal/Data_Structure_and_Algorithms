#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void CreateQueue(struct Queue * q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear =  -1;
    q->Q = (int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if(q -> rear == q->size - 1)
    {
        printf("queue is full \n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if(q->rear == q->front)
    {
        printf("queue is empty \n");
        return 0;
    }
    else
    { 
        x = q->Q[q->front + 1];
        q->Q[q->front + 1] = 0;
        q->front++;
        return x;
    }
}

void Display(struct Queue q)
{
    for(int i = q.front+1; i <= q.rear;i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue st;
    CreateQueue(&st,5);
    
    
    enqueue(&st, 2);
    enqueue(&st, 3);
    enqueue(&st, 4);

    dequeue(&st);
    dequeue(&st);

    Display(st);

    return 0;
}
