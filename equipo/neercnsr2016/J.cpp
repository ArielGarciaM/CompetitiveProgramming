#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const ll INF = 1e18;

struct node {
    int l, r;
    ll mn;
    node *left, *right;

    node(int l, int r) : l(l), r(r) {
        mn = INF;
        if(l != r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int pos, ll v) {
        if(r < pos || pos < l)
            return;
        if(l == r)
            mn = v;
        else {
            left->upd(pos, v);
            right->upd(pos, v);
            mn = min(left->mn, right->mn);
        }
    }

    ll qry(int rl, int rr) {
        if(rr < l || r < rl)
            return INF;
        if(rl <= l && r <= rr)
            return mn;
        return min(left->qry(rl, rr), right->qry(rl, rr));
    }
};

const int MAXN = 5e4 + 5;
int n;
ll t;
vector<ii> costs;
int dis[MAXN];
ll dp[MAXN];

bool check(int r) {
    node tree(1, n);
    tree.upd(1, -1);
    dp[1] = 0;
    for(int k = 2; k <= n; k++) {
        dp[k] = tree.qry(max(1, k - r), k - 1) + k;
        tree.upd(k, dp[k] + dis[k] - k);
    }
    return (dp[n] <= t);
}

int main() {
    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);
    cin >> n >> t;
    for(int i = 1; i <= n - 1; i++) {
        int c;
        cin >> c;
        while(!costs.empty() && costs.back().second >= c)
            costs.pop_back();
        costs.push_back({i, c});
    }
    for(int i = 2; i <= n - 1; i++)
        cin >> dis[i];
    int m = costs.size();
    int lo = 0, hi = m - 1;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        if(check(costs[mi].first))
            hi = mi;
        else
            lo = mi + 1;
    }
    cout << costs[lo].second << endl;
}