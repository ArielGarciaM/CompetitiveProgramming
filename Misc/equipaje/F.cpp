#include <bits/stdc++.h>
using namespace std;

const int MAXN = 405;
int n, k;
double memo[MAXN][MAXN];

double dp(int num, int rem) {
    if(memo[num][rem] != -1.0)
        return memo[num][rem];

    if(rem == 0)
        return (double)num;

    if(num == n) {
        double d = (0.5)*(dp(num, rem - 1) +dp(num - 1, rem - 1));
        return memo[num][rem] = d;
    }
    double d = (0.5)*(dp(num, rem - 1) + dp(num + 1, rem - 1));
    return memo[num][rem] = d;
}

int main() {
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXN; j++)
            memo[i][j] = -1.0;
    }
    cin >> n >> k;
    cout << fixed << setprecision(20) << dp(0, k) << endl;
}