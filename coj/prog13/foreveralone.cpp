#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int pre[MAXN][61];

void test_case() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for(int j = 1; j <= 60; j++)
            pre[i][j] = pre[i - 1][j] + (x == j);
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int j = 1; j <= 60; j++)
            ans += 2*((pre[r][j] - pre[l - 1][j])/2);
        cout << (r - l + 1) - ans << '\n';
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