#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
vector<int> divisible[MAXN];
int rep[MAXN], sz[MAXN], val[MAXN];

void init() {
    fill(rep, rep + MAXN, -1);
    fill(sz, sz + MAXN, 1);
}

int find(int u){
    return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return false;
    if(sz[u] > sz[v]) swap(u, v);
    rep[u] = v;
    sz[v] += sz[u];
    return true;
}

ll test_case() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
        for(int d = 1; d * d <= val[i]; d++) {
            if(val[i] % d == 0) {
                divisible[d].push_back(i);
                if(d * d < val[i])
                    divisible[val[i]/d].push_back(i);
            }
        }
    }
    init();
    ll ans = 0;
    for(int d = MAXN - 1; d >= 1; d--) {
        if(divisible[d].empty())
            continue;
        while(divisible[d].size() >= 2) {
            if(join(divisible[d][0], divisible[d].back()))
                ans += d;
            divisible[d].pop_back();
        }
        divisible[d].clear();
    }
    return ans;
}

int main() {
    freopen("dream.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        cout << "Case " << i << ": " << test_case() << '\n';
}