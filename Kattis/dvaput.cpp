#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

vi buildSA(string &s) {
    int n = s.size();
    vi SA(n), val(n);
    iota(SA.begin(), SA.end(), 0);
    vector<ii> rk(n);
    for(int i = 0; i < n; i++)
        val[i] = s[i];
    for(int l = 1; l < n; l <<= 1) {
        for(auto x : SA)
            rk[x] = {val[x], x + l < n ? val[x + l] : -1};
        sort(SA.begin(), SA.end(), [&](int a, int b){ return rk[a] < rk[b]; });
        val[SA[0]] = 0;
        for(int i = 1; i < n; i++)
            val[SA[i]] = val[SA[i - 1]] + (rk[SA[i]] != rk[SA[i - 1]]);
        if(val[SA[n - 1]] == n - 1) break;
    }
    return SA;
}

vi buildLCP(string &s, vi &SA) {
    int n = s.size(), L = 0;
    vi prv(n), plcp(n), lcp(n);
    prv[SA[0]] = -1;
    for(int i = 1; i < n; i++)
        prv[SA[i]] = SA[i - 1];
    for(int i = 0; i < n; i++) {
        if(prv[i] == -1)
            continue;
        while(i + L < n && s[prv[i] + L] == s[i + L]) L++;
        plcp[i] = L;
        L = max(L - 1, 0);
    }
    for(int i = 0; i < n; i++)
        lcp[i] = plcp[SA[i]];
    return lcp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vi SA = buildSA(s);
    vi lcp = buildLCP(s, SA);
    cout << *max_element(lcp.begin(), lcp.end()) << '\n';
}