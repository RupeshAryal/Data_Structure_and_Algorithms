

struct Node
{
    struct Node *LeftChild;
    int data;
    struct Node *RightChild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node  **Q; //array is going to store the address of Node
};

void CreateQueue(struct Queue * q, int size)
{
    q->size = size;
    q->front = 0;
    q->rear =  0;
    q->Q = (Node **)malloc(q->size*sizeof(Node *));
}

void enqueue(struct Queue *q, struct Node * x)
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

Node * dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if(q->rear == q->front)
    {
        printf("queue is empty \n");
    }
    else
    { 
       q->front = (q->front + 1) % q->size;
       x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}



