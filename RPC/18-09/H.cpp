#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 6;
int A[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int p;
    cin >> p;
    while(p--) {
        int x;
        cin >> x;
        A[x]++;
    }
    cin >> p;
    while(p--) {
        int x;
        cin >> x;
        A[x] += 2;
    }
    int ans = 0, last = 3;
    for(int i = 0; i < MAXN; i++) {
        if(A[i] == 0) continue;
        if(last == 3) { ans++; last = A[i]; }
        if(last == 1 && A[i] != 1) { ans++; last = A[i]; }
        if(last == 2 && A[i] != 2) { ans++; last = A[i]; }
    }
    cout << ans << endl;
}