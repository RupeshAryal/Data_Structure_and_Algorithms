#ifndef Chains_h
#define Chains_h
#include<stdio.h>
#include<stdlib.h>

struct Node{
   struct Node *next;
   int data;
}*first = NULL;

void SortedInsert(struct Node **linked_list, int x)
{
    struct Node *new_node;
    struct Node *p = *linked_list;
    struct Node *q = NULL; // to temporary store the p^th node

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;

    if(*linked_list == NULL)
    {
        *linked_list = new_node;
    }
       
    
    else
    {
        while(p && p->data < x)
        {   
            q = p;
            p = p->next;
        }
        if (p == *linked_list) //pointer to the first node of a list
        {
            new_node->next = *linked_list;
            *linked_list = new_node;
        }
        else
        {
            new_node->next = q->next;
            q->next = new_node;
        }        
    }
}

struct Node *Search(struct Node *p, int key)
{
    while(p!= NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
   
    return NULL; //if the linked list is empty
}

#endif

