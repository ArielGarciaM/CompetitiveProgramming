#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll A[MAXN], dp[256], mx[256];

int val(char c) {
    if('0' <= c && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        A[i] = 16*val(s[0]) + val(s[1]);
    }
    for(int i = 0; i < n; i++) {
        for(int k = 255; k >= 0; k--) {
            if(k > 0 && mx[k - 1] == 0) {
                //cout << k << " " << dp[k] << endl;
                continue;
            }
            ll an = dp[(255 + k)%256] + (k ^ A[i]) + 256ll*(mx[k]/256ll);
            if(an >= dp[k]) {
                dp[k] = an;
                mx[k] = mx[(255 + k)%256] + 1;
            }
            //cout << k << " " << dp[k] << endl;
        }
    }
    ll m = 0;
    for(int i = 0; i < 256; i++)
        m = max(m, dp[i]);
    cout << m << endl; 
}