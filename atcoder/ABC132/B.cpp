#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &x: p)
        cin >> x;
    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        if(p[i] > p[i - 1] && p[i] < p[i + 1])
            ans++;
        if(p[i] < p[i - 1] && p[i] > p[i + 1])
            ans++;
    }
    cout << ans << endl;
}