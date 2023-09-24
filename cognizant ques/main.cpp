#include <iostream>

using namespace std;

/*int countDigits(int num)
{
    int count=0,temp=num;
    while(temp!=0)
    {
        temp=temp/10;
        count++;
    }
    return (num%count);
}
*/
/*void arrayReverse(int len,int *arr)
{
int i,temp,originalLen=len;
for(i=0;i<originalLen/2;i++)
{
temp=arr[len-1];
arr[len-1]=arr[i];
arr[i]=temp;
len-=1;
}
for(int i=0; i<originalLen; i++){
        cout << arr[i];
    }
}*/
void removeElement(int size,int indexValue,int *inputList)
{
    int i;
    if(indexValue<size)
    {
        for(i=indexValue;i<size;i++)
        {
            inputList[i]=inputList[i+1];//1 2 3 4 5 6 7 8 9
        }
        for(i=0;i<size-1;i++)
            {
                cout << inputList[i];
            }
    }
    else
    {
        for(i=0;i<size;i++)
        {
            cout << inputList[i];
        }
    }
}
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int index;
    cin >> index;
    removeElement(n, index, a);
    //arrayReverse(n, a);
    //cout << countDigits(n);
    return 0;
}
