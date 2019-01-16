#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> ans;
set<ll> bad;
int n, r;

void dfs(ll s) {
    if(bad.find(s) == bad.end()) {
        ans.insert(s);
        return;
    }
    if(s >> n > 0)
        return;
    dfs(s << 1);
    dfs(s << 1 | 1);
}

int main() {
    cin >> n >> r;
    while(r--) {
        ll x;
        cin >> x;
        while(x > 0) {
            bad.insert(x);
            x >>= 1;
        }
    }
    dfs(1);
    for(ll x : ans)
        cout << x << " ";
    cout << endl;
}