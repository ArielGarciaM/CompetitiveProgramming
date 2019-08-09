#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char, ll> val;

void test_case() {
    ll m;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        char c;
        cin >> c;
        val[c] = i;
    }
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        ll po = 1, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            ans += val[s[i]] * po;
            po *= m;
        }
        cout << ans << '\n';
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        test_case();
}