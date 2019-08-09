#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int main() {
    for(int i = 1; i <= 1000000; i++) {
        dp[i] = i + 1;
        string s = to_string(i);
        for(auto c : s)
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
    }
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}