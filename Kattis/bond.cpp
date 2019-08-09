#include <bits/stdc++.h>
using namespace std;

int n;
double mat[20][20], memo[1<<20];

double dp(int msk) {
    if(memo[msk] > -0.5)
        return memo[msk];
    if(msk == 0)
        return 1.0;
    int c = __builtin_popcount(msk) - 1;
    double ans = -1.0;
    for(int i = 0; i < n; i++) {
        if(msk & (1 << i))
            ans = max(ans, mat[c][i] * dp(msk^(1 << i)));
    }
    return memo[msk] = ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            double p;
            cin >> p;
            mat[i][j] = p/100.0;
        }
    }
    for(int i = 0; i < (1 << 20); i++)
        memo[i] = -1.0;
    cout << fixed << setprecision(15) << 100.0*dp((1 << n) - 1) << endl;
}