#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

const ll MAXN = 250010;

struct shash {
    ll P, MOD, H[MAXN], po[MAXN];
    shash(string &s, ll P, ll MOD) : P(P), MOD(MOD) {
        po[0] = 1;
        for(int i = 1; i < MAXN; i++)
            po[i] = (P * po[i - 1]) % MOD;
        H[0] = s[0];
        for(int i = 1; i < s.length(); i++)
            H[i] = (P * H[i - 1] + s[i])%MOD;
    }

    ll gethash(int l, int r) {
        if(l > r)
            return 0;
        if(l == 0)
            return H[r];
        return ((H[r] - po[r - l + 1]*H[l - 1])%MOD + MOD)%MOD;
    }
};

gp_hash_table<int, int> st1;
gp_hash_table<int, int> st2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    shash h1 = shash(s, 31, 1000000007), h2 = shash(t, 31, 1000000007), h3 = shash(s, 37, 1000000009), h4 = shash(t, 37, 1000000009);
    //for(int i = 0; i < s.length(); i++)
    //    cout << h1.H[i] << endl;
    int lo = 0, hi = min(s.length(), t.length());
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        bool check = false;
        for(int i = 0; i + mi - 1 < s.length(); i++) {
            ll res1 = h1.gethash(i, i + mi - 1), res2 = h3.gethash(i, i + mi - 1);
            //cout << res << endl;
            st1[res1] = 1, st2[res2] = 1;
        }
        for(int i = 0; i + mi - 1 < t.length(); i++) {
            ll res1 = h2.gethash(i, i + mi - 1), res2 = h4.gethash(i, i + mi - 1);
            //cout << res << endl;
            if(st1[res1] == 1 && st2[res2] == 1) {
                check = true;
                break;
            }
        }
        st1.clear();
        st2.clear();
        if(check)
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << lo << endl;
}