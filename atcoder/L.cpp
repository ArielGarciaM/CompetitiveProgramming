#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3005;
ll memo[MAXN][MAXN], a[MAXN], n;

ll dp(int fst, int lst) {
    if(memo[fst][lst] != -1)
        return memo[fst][lst];
    if(fst > lst)
        return 0;
    if((lst - fst + 1) % 2 == n % 2)
        return memo[fst][lst] = max(a[fst] + dp(fst + 1, lst), a[lst] + dp(fst, lst - 1));
    else
        return memo[fst][lst] = min(dp(fst + 1, lst) - a[fst], dp(fst, lst - 1) - a[lst]);
}

int main() {
    memset(memo, -1, sizeof memo);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << dp(1, n) << endl;
}