#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int ans = INF;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    if(n == 1) {
        cout << "0\n";
        return 0;
    }
    for(int m = 0; m < 9; m++) {
        int t = m;
        int d1 = (t%3) - 1;
        t /= 3;
        int d2 = (t%3) - 1;
        int a = v[0] + d1, b = v[n - 1] + d2;
        if(((b - a)%(n - 1)) != 0)
            continue;
        int d = (b - a)/(n - 1);
        bool can = true;
        int ops = 0;
        for(int k = 0; k <= n - 1; k++) {
            if(v[k] == a + d*k)
                continue;
            if(abs(v[k] - (a + d*k)) > 1)
                can = false;
            else
                ops++;
        }
        if(!can) continue;
        ans = min(ans, ops);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}