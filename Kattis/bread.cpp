#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll BIT[MAXN];

void add(int p, ll val) {
    for(; p < MAXN; p += (p & -p))
        BIT[p] += val;
}

ll sum(int p) {
    ll res = 0;
    for(; p > 0; p -= (p & -p))
        res += BIT[p];
    return res;
}

int main() {
    int n;
    ll inv1 = 0, inv2 = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++) {
        inv1 += sum(n) - sum(v[i]);
        add(v[i], 1);
    }
    for(int i = 0; i < n; i++)
        cin >> v[i];
    memset(BIT, 0, sizeof BIT);
    for(int i = 0; i < n; i++) {
        inv2 += sum(n) - sum(v[i]);
        add(v[i], 1);
    }
    //cout << inv1 << " " << inv2 << endl;
    if(inv2 % 2 == inv1 % 2)
        cout << "Possible\n";
    else
        cout << "Impossible\n";
}