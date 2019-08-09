#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll n, x, hmod, pref[MAXN];

struct test {
    ll b, l, u;
    bool operator< (const test &o) const { return (b*l + (x - b)*u) > (o.b*o.l + (x - o.b)*o.u); }
};
vector<test> tests;

bool can(ll hrs) {
    ll hm = hrs % x, take = hrs / x;
    ll score = 0;
    for(int i = 0; i < n; i++)
        score -= tests[i].b * tests[i].l;
    ll bestGain = 0;
    for(int i = 0; i < n; i++) {
        test t = tests[i];
        ll gain = 0;
        if(i >= take)
            gain = pref[take - 1];
        else {
            gain = pref[take];
            gain -= (t.b*t.l + (x - t.b)*t.u);
        }
        gain += (hm >= t.b ? (t.l*t.b + (hm - t.b)*t.u) : hm*t.l);
        if(gain > bestGain && hrs == 2540) {
            cout << t.b << " " << t.l << " " << t.u << '\n';
        } 
        bestGain = max(gain, bestGain);
    }
    score += bestGain;
    return score >= 0ll;
}

int main() {
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        ll b, l, u;
        cin >> b >> l >> u;
        tests.push_back({b, l, u});
    }
    sort(tests.begin(), tests.end());
    cout << "INIT TESTS:\n";
    for(auto t : tests)
        cout << t.b << " " << t.l << " " << t.u << '\n';
    cout << "=========\n";
    for(int i = 0; i < n; i++) {
        test t = tests[i];
        pref[i] = t.b*t.l + (x - t.b)*t.u;
        if(i > 0)
            pref[i] += pref[i - 1];
    }
    ll lo = 0;
    ll hi = n*x;
    while(lo < hi) {
        ll mi = (lo + hi)/2ll;
        if(can(mi))
            hi = mi;
        else
            lo = mi + 1ll;
    }
    cout << lo << endl;
}