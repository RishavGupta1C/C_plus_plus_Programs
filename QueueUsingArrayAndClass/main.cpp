//#include<bits/stdc++.h>
#include <iostream>
//#define SIZE 3
// In this program if we enqueue till MAX_SIZE
// then we have to dequeue completely before inserting again.


using namespace std;

class Queue{
    private:
        const static int MAX_SIZE = 3;
        int front, rear, items[MAX_SIZE];
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        bool isFull();
        bool isEmpty();
        void enQueue(int);
        int deQueue();
        void display();
};

bool Queue::isFull(){
    if(rear == MAX_SIZE-1){
        //cout<<"The queue is full\n";
        return true;
    }else{
        //cout<<"The queue is not full\n";
        return false;
    }
}

bool Queue::isEmpty(){
    if(front == -1){
        //cout<<"The queue is empty\n";
        return true;
    }else{
        //cout<<"The queue is not empty\n";
        return false;
    }
}

void Queue::enQueue(int data) {
    if(isFull()) {
        cout<<"Overflow\n";
    }else{
        if(front == -1) // isEmpty()
            front = 0;
        items[++rear] = data;
        cout<<items[rear]<<" Inserted at "<<rear<<"\n";
    }
}

int Queue::deQueue(){
    if(isEmpty()){
        cout<<"UnderFlow\n";
        return -1;
    }else{
        int data = items[front];
        int position = front;
        if(front>=rear){
            front = -1;
            rear = -1;
        }else{
            front++;
        }
        cout<<data<<" Deleted from "<< (position)<<"\n";
        return data;
    }
}

void Queue::display(){
    if(isEmpty()){
        cout<<"Nothing to display\n";
    }else{
        cout<<"Front index -> "<<front
        <<"\nItems -> ";
        for(int i=front; i<=rear; i++){
            cout<<items[i]<<" ";
        }
        cout<<"\nRear Index -> "<<rear<<"\n";
    }
}
int main()
{
    Queue que;
    que.display();
    que.deQueue();
    que.enQueue(10);
    que.enQueue(20);
    que.enQueue(30);
    que.enQueue(40);
    que.display();
    que.deQueue();
    que.enQueue(50);
// Overflow despite one element being dequeued as rear has reached MAX_SIZE
// And empty spaces are present.
// So we have to dequeue entire queue to enqueue again.
// To overcome this limitation we use Circular Queue or Queue using Linked List.
    //que.deQueue();
    //que.deQueue();
    //que.deQueue();
    que.display();
    return 0;
}
