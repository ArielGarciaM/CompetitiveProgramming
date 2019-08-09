#include <bits/stdc++.h>
using namespace std;
map<int, int> m;

int main() {
    int n, pf = 0, ans = 0;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        m[a]++;
        m[b]--;
    }
    for(auto p : m) {
        pf += p.second;
        ans = max(ans, pf);
    }
    cout << ans << '\n';
}