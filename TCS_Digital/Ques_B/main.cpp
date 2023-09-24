#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d,s,a;
    cin >> d;
    cin >> s;
    int *sum = new int[d*2]();
    float *ans = new float[s]();
    for (int j=0;j<d*2; j++) {
        for(int i=0; i<s; i++) {
            cin >> a;
            sum[j] += a;
            //cout << sum[j] << "\n";
        }

        if(j%2 != 0){
            ans[j/2] = (float)sum[j-1]/(float)sum[j];
            //cout << ans[j/2] << "\n";
        }
    }
    for(int k=0; k<d-1; k++){
        if(ans[k+1] < ans[k]){
            cout << "Increasing\n" ;
        }
        else if(ans[k+1] > ans[k]){
            cout << "Decreasing\n";
        }
        else{
            cout << "Same\n";
        }
    }
    return 0;
}
