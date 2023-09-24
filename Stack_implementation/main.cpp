// The program to simulate your browser history
// Note to use a variable in array either use macro(#define) or use const static variable.


#include <iostream>
// #define MAX_SIZE 3

using namespace std;

class Stack{
    private :
        int top;
        const static int MAX_SIZE = 3;
        int size[MAX_SIZE];
    public :
        Stack(){
            top = -1;
        }
        int pop();
        bool push(int page);
        bool isEmpty();
};

bool Stack :: push(int page) {
    if(top >= MAX_SIZE-1){
        cout<<"Overflow\n";
        return false;
    }
    else{
        top++;
        size[top] = page;
        cout<<size[top]<<" has been pushed to position "<<top<<"\n";
        return true;
    }
}

int Stack:: pop() {
    if(top <= -1){
        cout<<"Underflow\n";
        return 0;
    }else{
        int page = size[top--];
        cout<<page<<" has been popped from position "<<(top+1)<<"\n";
        return page;
    }
}

bool Stack::isEmpty(){
    return (top <= -1);
}

int main()
{
    Stack pages;
    pages.pop();

    if(pages.isEmpty()){
        cout<<"Stack is empty\n";
    }else{
        cout<<"Stack is not empty\n";
    }

    pages.push(10);
    pages.push(20);
    pages.push(30);
    pages.push(40);

    if(pages.isEmpty()){
        cout<<"Stack is empty\n";
    }else{
        cout<<"Stack is not empty\n";
    }

    pages.pop();
    pages.pop();
    pages.pop();
    pages.pop();

    if(pages.isEmpty()){
        cout<<"Stack is empty\n";
    }else{
        cout<<"Stack is not empty\n";
    }
    return 0;
}
