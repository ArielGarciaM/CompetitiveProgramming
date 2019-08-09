#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> f(31);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i <= 30; i++)
        f[i].resize(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> f[0][i];
    for(int k = 1; k <= 30; k++)
        for(int i = 1; i <= n; i++)
            f[k][i] = f[k - 1][f[k - 1][i]];
    while(q--) {
        int x, k;
        cin >> x >> k;
        for(int l = 30; l >= 0; l--)
            if((1 << l) & k) x = f[l][x];
        cout << x << '\n';
    }
}