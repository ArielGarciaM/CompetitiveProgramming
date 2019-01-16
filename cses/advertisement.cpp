#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll mxin = 0;
set<ii> intervals;

void add(int pos) {
    int lb = pos, rb = pos;
    set<ii>::iterator it = intervals.lower_bound({pos + 1, 0});
    if(it != intervals.end() && it->first == pos + 1) {
        rb = it->second;
        intervals.erase(it);
    }
    it = intervals.lower_bound({pos, 0});
    if(it != intervals.begin()) {
        --it;
        if(it->second == pos - 1) {
            lb = it->first;
            intervals.erase(it);
        }
    }
    mxin = max(mxin, (ll)(rb - lb + 1));
    intervals.insert({lb, rb});
}

int main() {
    vector<ii> hs;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        hs.push_back({h, i});
    }
    sort(hs.begin(), hs.end(), [&](ii a, ii b){return a.first > b.first;});
    ll mh = 2e9, ans = 0;
    for(auto p : hs) {
        mh = min(mh, (ll)p.first);
        add(p.second);
        ans = max(ans, mh*mxin);
    }
    cout << ans << endl;
}