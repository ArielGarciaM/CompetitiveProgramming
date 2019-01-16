#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    map<char, pll> mp;
    mp['0'] = {0, 0};
    mp['1'] = {1, 0};
    mp['2'] = {0, 1};
    mp['3'] = {1, 1};

    string s;
    cin >> s;
    ll x = 0, y = 0;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        ll p = 1 << (n - i - 1);
        x += p*mp[s[i]].first;
        y += p*mp[s[i]].second;
    }
    cout << n << " " << x << " " << y << endl;
}