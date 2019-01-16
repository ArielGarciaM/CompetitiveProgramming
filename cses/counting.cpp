#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, ans = 0;
    cin >> n;
    for(long long b = 0; b <= 60; b++) {
        ans += (1ll << b)*(n/(1ll << (b + 1ll)));
        ans += max((n % (1ll << (b + 1ll))) - (1ll << b) + 1ll, 0ll);
    }
    cout << ans << endl;
}