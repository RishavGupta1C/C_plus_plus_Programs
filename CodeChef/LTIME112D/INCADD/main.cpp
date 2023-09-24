#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    // For fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    const long long MAXN = 1e5 + 5;
    int T, N, Q, nums[MAXN];
    cin >> T;
    while(T--) {
        cin >> N >> Q;
        for(int i=0; i<N; i++) cin >> nums[i];
        multiset<int> mst;      // mst stores the difference between the elements of nums.
        for(int i=1; i<N; i++) mst.insert(nums[i] - nums[i-1]);
        cout << "1:";
        for(auto it=mst.begin(); it != mst.end(); it++) {
            cout << " " << *it;
        }
        cout << "\n";
        while(Q--) {
            // INPUT QUERY
            int i, x;
            cin >> i >> x;
            i--;

            if(i < N-1) {
                auto iter = mst.find(nums[i+1] - nums[i]);
                mst.erase(iter);
            }

            if(i > 0) {
                auto iter = mst.find(nums[i] - nums[i-1]);
                mst.erase(iter);
            }
            cout << "2:";
            for(auto it=mst.begin(); it != mst.end(); it++) {
                cout << " " << *it;
            }
            cout << "\n";

            nums[i] = x;

            // INSERT DIFFERENCE TO MULTISET (set that can have duplicate values)
            if(i < N-1) {
                mst.insert(nums[i+1] - nums[i]);
            }

            if(i > 0) {
                mst.insert(nums[i] - nums[i-1]);
            }

            cout << "size: " << mst.size() << "\n";
            cout << "OUTPUT: ";
            if(mst.size()) {
                if(*mst.begin() < 0) {
                    cout << abs(*mst.begin()) << "\n";
                } else {
                    cout << 0 << "\n";
                }
            }
            cout << "3:";
            for(auto it=mst.begin(); it != mst.end(); it++) {
                cout << " " << *it;
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
