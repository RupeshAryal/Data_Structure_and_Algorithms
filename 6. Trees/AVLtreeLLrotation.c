#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *LeftChild;
    int data;
    int height;
    struct Node *RightChild;
}*root = NULL;

int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl= p && p->LeftChild? p->LeftChild->height:0;
    hr=  p && p->RightChild? p->RightChild->height:0;

    return hl > hr?hl+1:hr+1;
}

int BalanceFactor(struct Node *p)
{
    int hl, hr;
    hl= p && p->LeftChild? p->LeftChild->height:0;
    hr= p && p->RightChild? p->RightChild->height:0;

    return hl-hr;

}

int height(struct Node *root)
{
    int x = 0, y= 0;
    if (root == NULL)
    {
        return -1;
    }
    x = height(root->LeftChild); //go to left child recursively until you encounter NULL
    y = height(root->RightChild);//then go to right child recursively until you reach NULL

    if (x > y)
        return x + 1;
    else
        return y + 1;
}


struct Node * LRRotation(struct Node *p)
{
    struct Node *pl = p->LeftChild; //left child of root
    struct Node *plr = pl->RightChild;//right child of (left child of root)

    pl->RightChild = p;//make pl the root child and p the right child of pl
    p->LeftChild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;
    
    return pl;

}

struct Node * LLRotation(struct Node *p)
{
    struct Node *pl = p->LeftChild;
    struct Node *plr = p->RightChild;

    pl->RightChild = p;
    pl->LeftChild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;
    
    return pl;
}

struct Node * RLRotation(struct Node *p)
{
    return p;
}

struct Node * RRRotation(struct Node *p)
{
    return p;
}



struct Node *RecursiveInsert(struct Node *p, int value)
{
    struct Node *t = NULL;

    if (p==NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = value;
        t->height = 0;
        t->LeftChild = t->RightChild = NULL;
        return t;
    }
    if (value < p->data)
        p->LeftChild = RecursiveInsert(p->LeftChild, value);
    else if(value > p->data)
        p->RightChild = RecursiveInsert(p->RightChild, value);
    
    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->LeftChild) == 1)
        return LLRotation(p);

    else if (BalanceFactor(p) == 2 && BalanceFactor(p->LeftChild) == -1)
        return LRRotation(p);

    else if (BalanceFactor(p) == -2 && BalanceFactor(p->LeftChild) == 1)
        return LLRotation(p);

    else if (BalanceFactor(p) == -2 && BalanceFactor(p->LeftChild) == 1)
        return RLRotation(p);


    return p;   
}

int main()
{
    
    root=RecursiveInsert(root, 9);
    RecursiveInsert(root, 8);
    RecursiveInsert(root, 7);
    RecursiveInsert(root, 6);
    RecursiveInsert(root, 5);
    RecursiveInsert(root, 4);
    RecursiveInsert(root, 3);
    RecursiveInsert(root, 2);


    printf("%d", root->data);

    return 0;;
}