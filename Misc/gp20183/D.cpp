#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        ans += (x == 1 ? 0 : 1);
    }
    cout << ans << endl;
}