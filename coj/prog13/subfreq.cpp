#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

vector<ii> res;

bool cmp(ii p1, ii p2) {
    if(p1.second != p2.second) return p1.second > p2.second;
    return p1.first < p2.first;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n), a(k);
    for(auto &x : v) cin >> x;
    for(auto &x : a) cin >> x;
    sort(v.begin(), v.end());
    for(auto t : a) {
        int L = 0, R = n - 1, ans = 0;
        while(L < R) {
            if(v[L] + v[R] < t)
                L++;
            else {
                if(v[L] + v[R] == t) ans++;
                R--;
            }
        }
        res.push_back({t, ans});
    }
    sort(res.begin(), res.end(), cmp);
    for(auto p : res)
        cout << p.first << " " << p.second << '\n';
}