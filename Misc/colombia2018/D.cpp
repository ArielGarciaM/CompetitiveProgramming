#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll pref[MAXN], x[MAXN], y[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for(int i = 1; i <= n; i++) {
        if(i < n)
            pref[i] = pref[i - 1] + x[i]*y[i + 1] - x[i + 1]*y[i];
        else
            pref[i] = pref[i - 1] + x[i]*y[1] - x[1]*y[i];
    }
    ll A = abs(pref[n]), ans = 0;
    while(m--) {
        int l, r;
        cin >> l >> r;
        if(l > r)
            swap(l, r);
        ll T = (pref[r - 1] - pref[l - 1]) + x[r]*y[l] - x[l]*y[r];
        T = abs(T);
        ans = max(ans, min(T, A - T));
    }
    cout << fixed << setprecision(10) << (double)(ans)*0.5 << endl;
}