// Program to find the fare where BusStops[] array has stop name and Path[] array has distance between two paths.
#include <bits/stdc++.h>

using namespace std;

int getFare(string src, string dest){
    char BusStops[8][3] = {"TH", "GA", "IC", "HA", "TE", "LU", "NI", "CA"};
    int dist = 0, Path[] = {800, 600, 750, 900, 1400, 1200, 1100, 1500};
    int s,d;
    for(int i=0; i<8; i++){
        if(src == BusStops[i]){
            s = i;
        }
        if(dest == BusStops[i]){
            d = i;
        }
    }
    if(s==d){
        cout<<"INVALID INPUT";
        return -1;
    }
    if(d<s){
        for(int i=s+1; i<8; i++){
            dist += Path[i];
        }
    }
    for (int i=0; i<=d; i++){
        dist += Path[i];
    }
    cout << dist << "\n";
    // cout<<fixed;
    //cout.precision(1);
    float fare = ceil(((float)dist/(float)1000) * 5);
    cout << fixed << setprecision(1) << fare << " INR";
    return 0;
}
int main()
{
    string source, destination;
    cin >> source;
    cin >> destination;
    getFare(source, destination);
    return 0;
}
