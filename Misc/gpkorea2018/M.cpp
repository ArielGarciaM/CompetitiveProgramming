#include <bits/stdc++.h>
using namespace std;

int ans[1005];

int main() {
    int n, k, A;
    cin >> n >> k >> A;
    for(int i = 0; i < n; i++) {
        int t, s;
        cin >> t >> s;
        if(k % (A*t) == 0)
            ans[i] = (k/(A*t))*(s + t) - s;
        else {
            ans[i] = (k/(A*t))*(s + t);
            ans[i] += (k%(A*t) + A - 1)/A;
        }
    }
    int mn = 1e9;
    for(int i = 0; i < n; i++)
        mn = min(ans[i], mn);
    cout << mn << endl;
}