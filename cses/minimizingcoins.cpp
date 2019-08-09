#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1000001];

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto &y : v)
        cin >> y;
    iota(dp, dp + x + 1, 1);
    dp[0] = 0;
    for(int w = 1; w <= x; w++)
        for(auto c : v)
            if(w >= c)
                dp[w] = min(dp[w], dp[w - c] + 1);
    cout << (dp[x] <= x ? dp[x] : -1) << '\n';
}