#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

struct line {
    ll m, b;
    ll eval(ll x) { return m*x + b; }
    ll div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b);}
    ll isect(const line &o) { return div(b - o.b, o.m - m); }
};
deque<line> dq;

ll query(ll x) {
    while(dq.size() >= 2 && dq.back().eval(x) <= dq[dq.size() - 2].eval(x))
        dq.pop_back();
    return dq.back().eval(x);
}

void add(ll m, ll b) {
    line l = line {m, b};
    while(dq.size() >= 2 && dq[0].isect(l) >= dq[0].isect(dq[1]))
        dq.pop_front();
    dq.push_front(l);
}

ll dp[50005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ii> v;
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    sort(v.begin(), v.end());
    stack<ii> st;
    for(int i = 0; i < n; i++) {
        ii cur = v[i];
        while(!st.empty() && st.top().second <= cur.second)
            st.pop();
        st.push(cur);
    }
    vector<ii> qry;
    while(!st.empty()) {
        qry.push_back(st.top());
        st.pop();
    }
    reverse(qry.begin(), qry.end());
    dp[0] = 0;
    int m = qry.size();
    for(int i = 1; i <= m; i++) {
        add(qry[i - 1].second, -dp[i - 1]);
        dp[i] = -query(-qry[i - 1].first);
    }
    cout << dp[m] << endl;
}