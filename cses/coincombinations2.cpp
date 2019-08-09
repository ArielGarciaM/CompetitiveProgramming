#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll dp[1000001];

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto &y : v)
        cin >> y;
    dp[0] = 1;
    for(auto c : v)
        for(int w = 1; w <= x; w++)
            if(w >= c) {
                dp[w] += dp[w - c];
                if(dp[w] >= MOD) dp[w] -= MOD;
            }
    cout << dp[x] << '\n';
}