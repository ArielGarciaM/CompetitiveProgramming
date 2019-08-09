#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll ans[15] = {1, 3, 15, 75, 391, 2065, 11091, 60215, 330003, 1820869, 10103153, 56313047, 315071801, 1768489771, 9953853677};

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
}