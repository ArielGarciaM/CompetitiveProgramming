#include <bits/stdc++.h>
using namespace std;
#define S cin

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n, x, s;
    S >> t;
    while(t--) {
        S >> n, s = 0;
        while(n--)
            S >> x, s ^= x&3;
        cout << (s ? "first " : "second ");
    }
}