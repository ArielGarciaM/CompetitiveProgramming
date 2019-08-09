#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int dp[MAXN], a[MAXN];

void test_case() {
    int n;
    cin >> n;
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a[x] = y;
        dp[i] = n + 1;
    }
    for(int i = 1; i <= n; i++) {
        int lo = 0, hi = n;
        while(lo < hi) {
            int mi = (lo + hi + 1)/2;
            if(dp[mi] < a[i])
                lo = mi;
            else
                hi = mi - 1;
        }
        dp[lo + 1] = min(dp[lo + 1], a[i]);
    }
    for(int i = n; i >= 1; i--) {
        if(dp[i] <= n) {
            cout << n - i << '\n';
            break;
        }
    } 
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        test_case();
}