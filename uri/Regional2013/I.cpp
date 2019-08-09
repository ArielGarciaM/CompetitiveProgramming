#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll mx[55];

struct node {
    ll idx, dep, val;
    bool operator< (const node& o) const { return make_tuple(dep, -val, idx) > make_tuple(o.dep, -o.val, o.idx); }
};

void solve() {
    for(int i = 0; i < 55; i++)
        mx[i] = 1;
    set<node> active;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        active.insert({i, x, -1});
        //cout << i << " " << x << " " << -1 << " " << 1 << endl;
    }
    int cur = n + 1;
    while(active.size() > 1) {
        node le = *active.begin();
        active.erase(active.begin());
        node ri = *active.begin();
        active.erase(active.begin());
        if(ri.val == -1) {
            ri.val = mx[ri.dep + 1];
            mx[ri.dep] = max(mx[ri.dep], ri.val);
        }
        if(le.val == -1) {
            le.val = mx[le.dep + 1];
            mx[le.dep] = max(mx[le.dep], le.val);
        }
        //cout << le.val << " " << ri.val << endl;
        node par = {cur++, le.dep - 1, le.val + ri.val};
        mx[par.dep] = max(mx[par.dep], par.val);
        active.insert(par);
    }
    cout << active.begin()->val << endl;
}

int main() {
    while(cin >> n)
        solve();
}