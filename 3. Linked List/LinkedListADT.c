#include<stdio.h>
#include<stdlib.h>
#include<climits>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL, *second = NULL, *third = NULL;


void create(int A[], int n, struct Node* &node_names)
{
    int i;
    struct Node *t, *last;
    node_names = (struct Node *)malloc(sizeof(struct Node));
    node_names->data=A[0];
    node_names->mer next = NULL;
    last = node_names;

    for(i = 1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

int RecursiveCount(struct Node *p)
{
    if (p != NULL)
    {
        return RecursiveCount(p -> next) + 1;
    }
    else
        return 0;
}

int sum(struct Node *p)
{
    int sum = 0;

    while(p!= NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int RecursiveSum(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return RecursiveSum(p -> next) + p->data;
}

int count(struct Node *p)
{
    int l = 0;
    while(p)
    {
        l++;
        p = p -> next;
    }
    return l;
}

int max(struct Node *p)
{
    int max = INT_MIN;
    
    while(p)
    {
        if(p->data > max)
            max = p -> data;
        p = p->next;
    }
    return max;
}

int RecursiveMax(struct Node *p)
{
    int x=0;

    if(p==0)
        return INT_MIN;
    
    x = RecursiveMax(p -> next);
    if(x>p->data)
        return x;
    else
        return p-> data;

}

int min(struct Node *p)
{
    int min = INT_MAX;

    while(p != NULL)
    {
        if(p -> data < min)
            min = p -> data;
            p = p->next;
    }
    return min;
}

int RecursiveMin(struct Node *p)
{
    int x = 0;
    if (p == NULL)
    {
        return INT_MIN;
    }
    x = RecursiveMax(p -> next);
    if(x < p->data)
        return x;
    else
        return p->data;
}

void Display(struct Node *p)
{

    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p-> next;
    }
}

void DisplayRecursive(struct Node *p)
{
    if(p!= NULL)
    {
        printf("%d", p->data);
        DisplayRecursive(p -> next );
    }
}

struct Node * Lsearch(struct Node *p, int key)
{
    struct Node *q;

    while(p!= NULL)
    {
        if(key == p->data)
        {
            q -> next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node * RecursiveSearch(struct Node *p, int key)
{
    if(p == NULL)
            return NULL;
    if(key == p->data)
        return p;
    return RecursiveSearch(p->next,key);
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if(index < 0 || index > count(p))
        return;
    
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index == 0)
    {
        t -> next = first;
        first = t;
    }
    else
    {
        for(int i = 0;i < index; i++)
        {
            p = p->next;
            t->next = p->next;
            p->next = t;
           
            
        }
    }
}

void InsertLast(int x)
{
    struct Node *last;
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(first = NULL)
    {
       first = last = t;
    }
    else
    {
        last -> next = t;
        last = t;
    }

}

void InsertSorted(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = t;
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
            t->next = q-> next;
            q->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1;

    if(index < 1 || index > count(p))
        return -1;
    if(index == 1)
    {
        q = first;
        x  = first ->data;
        first = first -> next;
        free(q);
        return x;
    }
    else
    {
        for(int i = 0; i < index-1;i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
return x;
}

int IsSorted(struct Node *p)
{
    int x = -65536;
    while(p!= NULL)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    while(q!=NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p -> next = q->next;
            free(q);
            q=p->next;
        }
    }
}

void ReverseUsingArray(struct Node *p)
{
    int *A;
    struct Node *q = p;
    int i = 0;
    A = (int *)malloc(sizeof(int) * count(p));

     while(q!= NULL)
     {
        A[i] = q->data;
         q = q->next;
         i++;
     }

     q = p;
     i--;
     while(q!= NULL)
     {
        q -> data = A[i];
        q = q->next;
        i--;
     }
}

void ReverseUsingPointers(struct Node *p)
{
    struct  Node *q=NULL, *r = NULL;

    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q -> next = r;
    }
    first =q;
}

void ReverseRecursive(struct Node *q, struct Node *p)
{
    if(p)
    {
        ReverseRecursive(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

void Concatenation(struct Node *p, struct Node *q)
{
    third = p;
    while(p->next!=NULL)
    {
        p = p->next;
    }

    p -> next = q;
    q = NULL;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
     {
        third = last = q;
        q = q->next;
        third->next = NULL;
     } 
    while( p && q)
    {
        if(p->data < q->data)
        {
            last -> next = p;
            last = p;
            p = p->next;
            last -> next = NULL;
        }
        else
        {
            last -> next = q;
            last = q;
            q = q->next;
            last -> next = NULL;
        }
    }
    if(p) last -> next = p;
    if(q) last -> next = q;
}

int isloop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q?q->next:q;
    }while(p && q && p!=q);

    if(p = q)
        return 1;
    else
        return 0;


}


int main()
{
    int A[] = {1,3,5,7,9};
    int B[] = {2,4,6,8,10};

    create(A, 5, first);
    struct Node *t1, *t2;

    //t1 = first->next->next;
    //t2 = first->next->next->next->next;
    //t2->next = t1;

    printf("%d \n", isloop(first));
    

  return 0;
}