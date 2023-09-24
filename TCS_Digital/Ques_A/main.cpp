#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r1, r2, r3, n1, ans1, ans2;
    cin >> r1 >> r2 >> r3;
    cin >> n1;
    ans1 = (r1 * n1)/r2;
    ans2 = (ans1*r2)/r3;
    cout<<ans2;
    return 0;
}
