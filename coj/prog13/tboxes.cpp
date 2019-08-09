#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int mn = INT_MAX, mx = INT_MIN;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
        cout << mn + mx << '\n';
    }
}