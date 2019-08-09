#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int bal = 0;
        for(auto c : s)
            bal += (c - '0');
        for(auto c : t)
            bal -= (c - '0');
        cout << (bal ? "NO\n" : "YES\n");
    }
}