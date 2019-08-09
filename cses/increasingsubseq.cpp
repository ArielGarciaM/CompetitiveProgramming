#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &v) {
    int n = v.size();
    vector<int> dp(n + 1);
    fill(dp.begin(), dp.end(), 2e9);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        auto it = upper_bound(dp.begin(), dp.end(), v[i] - 1);
        *it = min(*it, v[i]);
    }
    for(int i = n; i >= 0; i--)
        if(dp[i] < 2e9) return i;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    cout << lis(v) << endl;
}