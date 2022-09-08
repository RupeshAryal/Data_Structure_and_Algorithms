#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};


class Stack
{
    private:
        Node *top;
    public:
        Stack()
        {
            top = NULL;
        }

        void push(int x)
        {
            Node *t = new Node;
            if(t == NULL)
                cout << "stack is full";
            else
            {
                t->data = x;
                t->next = top;
                top = t;
            }
        }

        int pop()
        {
            int x = -1;
            if(top == NULL)
                cout << "stack is empty \n";

            else
            {

                x = top->data;
                Node *t = top;
                top = top->next;
                delete t;
            }
            return x;
        }

        void Display()
        {
            Node *p = top;
            while(p != NULL)
            {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }   
};


int main()
{
    Stack stk;

    stk.push(10);
    stk.push(1);
    stk.push(12);
    stk.push(10);
    
    stk.Display();

    return 0;
}