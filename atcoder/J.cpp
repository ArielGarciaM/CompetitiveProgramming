#include <bits/stdc++.h>
using namespace std;

const int MAXN = 303;
double memo[MAXN][MAXN][MAXN];
int n;

double dp(int i, int j, int k) {
    if(i < 0 || j < 0 || k < 0)
        return 0.0;
    if(memo[i][j][k] != 0.0)
        return memo[i][j][k];
    if(i == 0 && j == 0 && k == 0)
        return 0.0;
    double ex = (double)(n - i - j - k)/((double)(i + j + k));
    double p = 0.0;
    if(i > 0)
        p += ((double)i)*(dp(i - 1, j + 1, k) + 1.0);
    if(j > 0)
        p += ((double)j)*(dp(i, j - 1, k + 1) + 1.0);
    if(k > 0)
        p += ((double)k)*(dp(i, j, k - 1) + 1.0);
    p /= (double)(i + j + k);
    return memo[i][j][k] = ex + p;
}

int main() {
    cin >> n;
    int ct1 = 0, ct2 = 0, ct3 = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 1)
            ct1++;
        if(x == 2)
            ct2++;
        if(x == 3)
            ct3++;
    }
    cout << fixed << setprecision(15) << dp(ct3, ct2, ct1) << endl;
}