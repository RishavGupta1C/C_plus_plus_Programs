#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ni, ne;
    float area1=0.0, area2 = 0.00;
    cin >> ni;
    cin >> ne;
    if(ni!=0){
        float *area_in = new float[ni];
        for(int i=0; i<ni; i++){
            cin >> area_in[i];
            area1+=area_in[i];
        }
    }
    if(ne!=0){
        float *area_out = new float[ne];
        for(int i=0; i<ne; i++){
            cin>> area_out[i];
            area2+=area_out[i];
        }
    }
    float cost = area1*18 + area2*12;
    cout<< "Total estimated Cost:"<< fixed << setprecision(1) << cost << " INR";
    return 0;
}
