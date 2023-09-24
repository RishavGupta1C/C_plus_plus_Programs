// C++ program to demonstrate static
// variables inside a class
// the static variables in a class are shared by the objects.
// There can not be multiple copies of same static variables for different objects.
// Also because of this reason static variables can not be initialized using constructors.
// Just like static variables, Static objects have a scope till the lifetime of program
// static member functions are called using 'classname::fuction()' not 'object.function'.

#include<iostream>
using namespace std;

class GfG
{
   public:
     static int i;

     GfG()
     {
        // Do nothing
     };
};

int GfG::i=2;

int main()
{
  GfG obj1;
  GfG obj2;
// We can not create multiple copies of the static variable i for multiple objects
//  obj1.i = 2;     undefined reference to i
//  obj2.i = 3;     undefined reference to i

  // prints value of i
  cout << obj1.i<<" "<<obj2.i;
}
/*
#include<iostream>
using namespace std;

class Test
{
private:
    static int count;
public:
    Test& fun();
};

int Test::count = 0;

Test& Test::fun()
{
    Test::count++;
    cout << Test::count << " ";
    return *this;
}

int main()
{
    Test t;
    t.fun().fun().fun().fun();
    return 0;
}
Output: 1 2 3 4
*/
