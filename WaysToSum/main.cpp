// C++ implementation to count ways
// to sum up to a given value N
#include <bits/stdc++.h>

using namespace std;

// function to count the total
// number of ways to sum up to 'N'
int countWays(int arr[], int m, int N)
{
    int count[N + 1];
    memset(count, 0, sizeof(count));

    // base case
    count[0] = 1;

    // count ways for all values up
    // to 'N' and store the result
    for (int i = 0; i < m; i++)
        for (int j = arr[i]; j <= N; j++)

            // if i >= arr[j] then
            // accumulate count for value 'i' as
            // ways to form value 'i-arr[j]'
            //if (i >= arr[j])
                count[j] += count[j - arr[i]];

    // required number of ways
    return count[N];

}

// Driver code
int main()
{
    int k;
    cin>>k;
    int arr[k];
    for(int i=0; i<k; i++) {
        arr[i] = i+1;
    }
    int total;
    cin>> total;
    cout << "Total number of ways = "
        << countWays(arr, k, total);
    return 0;
}
