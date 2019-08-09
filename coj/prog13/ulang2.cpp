#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char alph[26];

void test_case() {
    ll m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        char c;
        cin >> c;
        alph[i] = c;
    }
    int q;
    cin >> q;
    while(q--) {
        ll p;
        cin >> p;
        if(m == 1) {
            string res;
            while(p--) res += alph[0];
            cout << res << '\n';
        }
        else {
            ll len = 1, tot = 1;
            while(true) {
                if(m * tot + 1 > p) break;
                tot = m *tot + 1;
                len++;
            }
            p -= tot;
            string res;
            for(int i = 0; i < len; i++) {
                res += alph[p % m];
                p /= m;
            }
            reverse(res.begin(), res.end());
            cout << res << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        test_case();
}