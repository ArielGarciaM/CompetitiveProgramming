#include <bits/stdc++.h>
using namespace std;

using bs = bitset<1005>;
bs lights, s[1005];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int l;
    cin >> l;
    while(l--) {
        int x;
        cin >> x;
        lights.set(x);
    }
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while(k--) {
            int x;
            cin >> x;
            s[i].set(x);
        }
    }
    for(int i = 0; i < 3*n; i++) {
        lights ^= s[i % n];
        if(lights.count() == 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}