#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    for(int i = 0; i < n; i++) {
        int s, t, b;
        cin >> s >> t >> b;
        events.push_back({s, b});
        events.push_back({t, -b});
    }
    sort(events.begin(), events.end());
    int buckets = 0, mx = 0;
    for(auto p : events) {
        buckets += p.second;
        mx = max(buckets, mx);
    }
    cout << mx << endl;
}