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
    q->front = 0;
    q->rear =  0;
    q->Q = (int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if((q -> rear+1)%q->size == q->front)
    {
        printf("queue is full \n");
    }
    else
    {
        q->rear = (q->rear + 1)%q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if(q->rear == q->front)
    {
        printf("queue is empty \n");
    }
    else
    { 
       q->front = (q->front + 1) % q->size;
       x = q->front;
    }
    return x;
}

void Display(struct Queue q)
{

    int i = q.front+1;

    
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1)%q.size;
    }while(i!=(q.rear + 1)%q.size);
    printf("\n");
}

int main()
{
    struct Queue st;
    CreateQueue(&st,5);
    
    
    enqueue(&st, 2);
    enqueue(&st, 3);
    enqueue(&st, 4);
    enqueue(&st, 5);


    dequeue(&st);
    dequeue(&st);

    Display(st);

    return 0;
}
