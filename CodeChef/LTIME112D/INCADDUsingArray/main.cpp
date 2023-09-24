#include <iostream>
#define fastIO()             \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);             \
    cout.tie(0);

using namespace std;

static int ans;
static int pos;

void solve(int N, int A[]) {
    int i, x;
    cin >> i >> x;
    i--;
    A[i] = x;
    //cout << "ans: " << ans << "\n";

    if(i>0 && A[i-1]-A[i] == ans) {
        int previous = A[0];
        int temp[N];
        temp[0] = 0;
        for(int j=1; j<N; j++) {
            temp[j] = temp[j-1];
            if(A[j]-previous < 0) {
                if(previous-A[j] > temp[j]) {
                    temp[j] = previous-A[j];
                    pos = j;
                }
            }
            previous = A[j];
        }
        ans = temp[N-1];
    }

    if(i<N-1 && A[i+1]-A[i] == ans) {
        ans = 0;
        A[i] = x;
        int previous = A[0];
        int temp[N];
        temp[0] = 0;
        for(int j=1; j<N; j++) {
            temp[j] = temp[j-1];
            if(A[j]-previous < 0) {
                if(previous-A[j] > temp[j]) {
                    temp[j] = previous - A[j];
                    pos = i;
                }
            }
            previous = A[j];
        }
        ans = temp[N-1];
    }

    A[i] = x;
    if(i != 0) {
        if(A[i-1] > x) {
            if(A[i-1]-x > ans) {
                ans = A[i-1] - x;
            }
        }
    }
    if(i != N-1) {
        if(x > A[i-1]) {
            if(x-A[i+1] > ans) {
                ans = x - A[i+1];
            }
        }
    }
    cout << ans << "\n";
}

void solutionForINCADD() {
    int N, Q, previous;
    cin >> N >> Q;
    int A[N], temp[N];
    for(int i=0; i<N; i++) {
        temp[i] = 0;
        cin >> A[i];
    }
    previous = A[0];
    for(int i=1; i<N; i++) {
        temp[i] = temp [i-1];
        if(A[i] - previous < 0) {
            if(previous - A[i] > temp[i]) {
                temp[i] = previous - A[i];
                pos = i;
            }
        }
        previous = A[i];
    }
    ans = temp[N-1];
    //cout << "ans & size of temp: " << ans << " " << sizeof(temp)/sizeof(int) << "\n";
    while(Q--)
        solve(N, A);
}
int main() {
    // output will be printed after taking all the input
    // fastIO();
    int T;
    cin >> T;
    while(T--)
        solutionForINCADD();

    return 0;
}
