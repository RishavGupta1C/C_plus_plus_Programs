#include <iostream>

using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}node;

class Queue{
    private:
        node *front;
        node *rear;
        node *current;
    public:
        Queue(){
            front = NULL;
            rear = NULL;
            current = NULL;
        }
        void enQueue(int);
        void deQueue();
        void traverse();
};
/*
void Queue::enQueue(int element){
    cout<<"Pushing";
    if(front==NULL)
    {
        rear=(node*)malloc(sizeof(node));
        rear->data=element;
        rear->next=NULL;
        front=rear;
    }
    else
    {
        rear->next=(node*)malloc(sizeof(node));
        rear=rear->next;
        rear->data=element;
        rear->next=NULL;
    }
}*/

void Queue::enQueue(int element){
    cout<<"\nInserting";
    node *np = new node;
    np->data=element;
    np->next=NULL;
    if(front==NULL)
    {
        front=rear=np;
        //rear->next=NULL;    // Useless line I guess as np->next=NULL
    }
    else
    {
        rear->next=np;
        rear=np;
        //rear->next=NULL;    // Useless line I guess as np->next=NULL
    }
}

void Queue::deQueue()
{
    cout<<"\nRemoving";
    if(front==NULL)
    {
        printf("\nQueue is empty ! Underflow!!");
    }
    else
    {
        current=front->next;
        delete(front);
        front=current;
    }
}

void Queue::traverse()
{
    if(front == NULL){
        cout<<"\nNothing to traverse";
    }
    current=front;
    printf("\n");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
}


int main()
{
    Queue que;
    int choice,ch,item;
    do
    {
        printf("\n\t  --Main Menu--");
        printf("\n\t 1. Insert a node");
        printf("\n\t 2. Delete a node");
        printf("\n\t 3. Traverse the Queue");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the element you want to insert: ");
                    scanf("%d",&item);
                    que.enQueue(item);
                    break;
            case 2: que.deQueue();
                    break;
            case 3: que.traverse();
                    break;
            default: printf("\nYou have entered the wrong choice, try again!");
            }
            printf("\nDo you want to continue[1/0]: ");
            scanf("%d",&ch);
    }while(ch);
    return 0;
}
