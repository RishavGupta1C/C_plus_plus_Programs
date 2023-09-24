#include <bits/stdc++.h>

using namespace std;

void swap_num(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


template <size_t s>

void bubblesort(int (&arr1) [s]){
    int c = 0;
    int n = s;                              // length of the array arr1
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr1[j] > arr1[j+1]){
                    swap_num(&arr1[j],&arr1[j+1]);
                    c++;
            }
        }
    }
    cout<<c<<"\n";
    for(int i=0; i<n; i++)
        cout<<arr1[i]<<" ";
}

template <size_t s>
void optimised_bubblesort(int (&arr1)[s]){
    int c = 0;
    // s can also be used directly as the length
    int n = s;                             // length of the array arr1
    for(int i=0; i<n-1; i++){
        int flag = 0;
        for(int j=0; j<n-i-1; j++){
            if(arr1[j] > arr1[j+1]){
                    flag = 1;
                    swap_num(&arr1[j],&arr1[j+1]);
                    c++;
            }
        }
        if(!flag){
            break;
        }
    }
    cout<<"\n"<<c<<"\n";
    for(int i=0; i<n; i++)
        cout<<arr1[i]<<" ";
}


template<size_t n>
void selection_sort(int (&arr) [n]){        // n is unsigned integer
    int c = 0;
    for(int i=0; i<n-1; i++)                 // will give warning comparison of signed and unsigned integer
    {                                       // to remove this warning just write int s = n; and for(int i=0; i<s; i++)
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        swap_num(&arr[i],&arr[min]);
        c++;
    }
    cout<<"\n"<<c<<"\n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}


template<size_t n>
void insertion_sort(int (&arr)[n])
{

}
int main()
{
    int n, arr[5];
    memset(arr,0,sizeof(arr));              // initialize every element of the array arr to zero
    n = sizeof(arr)/sizeof(arr[0]);         // length of the array arr
    for(int i=0; i<n; i++)
        cout<<arr[i];
    cout<<"\n";


    // Bubble sort
    int arr1[7] = {64, 34, 25, 12, 22, 11, 90 };
    // Method 1 find the size in the main program and pass it as the parameter
    //int sizeOfArray = sizeof(arr1)/sizeof(arr1[0]);
    //bubblesort(arr1, sizeOfArray);
    // Method 2 find the size using template
    bubblesort(arr1);


    // Optimized bubble sort
    int arr2[7] = {64, 34, 25, 12, 22, 11, 90 };
    //sizeOfArray = sizeof(arr2)/sizeof(arr2[0]);
    optimised_bubblesort(arr2);


    // Selection Sort
    int arr3[7] = {90, 11, 12, 22, 25, 34, 64};     // worst possible case
    selection_sort(arr3);
    return 0;
}
