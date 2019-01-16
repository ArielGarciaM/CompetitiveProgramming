#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int LIS(vector<int> &S) {
    vector<int> prev(S.size());
    vector<ii> res;
    for(int i = 0; i < S.size(); i++) {
        ii el {S[i], i};
        auto it = lower_bound(res.begin(), res.end(), ii{S[i], 0});
        if(it == res.end()) {
            res.push_back(el);
            it = --res.end();
        }
        *it = el;
        prev[i] = (it == res.begin() ? 0 : (it - 1)->second);
    }
    return res.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ii tv;
    int tx, ty;
    cin >> tx >> ty;
    tv = {tx, ty};
    int n;
    cin >> n;
    map<ii, set<ii>> pts;
    for(int i = 0; i < n; i++) {
        int x, y, h;
        cin >> x >> y >> h;
        x -= tx;
        y -= ty;
        int d = abs(__gcd(x, y));
        ii p = {x/d, y/d};
        int di = 0;
        if(abs(x) != 0)
            di = abs(x);
        else
            di = abs(y);
        pts[p].insert({di, h});
    }
    int ans = 0;
    for(auto t : pts) {
        auto s = t.second;
        vector<int> v;
        for(auto p : s)
            v.push_back(p.second);
        ans += LIS(v);
    }
    cout << ans << endl;
}