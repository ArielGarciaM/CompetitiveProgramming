#include <bits/stdc++.h>
using namespace std;

int adj[10][10];
bool ind[1 << 10];
int memo[1 << 10];

int dp(int msk) {
    if(msk == 0)
        return 0;
    if(memo[msk] != -1)
        return memo[msk];
    memo[msk] = 100;
    for(int sm = msk; sm > 0; sm = (sm - 1)&msk) {
        if(ind[sm])
            memo[msk] = min(memo[msk], 1 + dp(msk ^ sm));
    }
    return memo[msk];
}

int main() {
    int n;
    while(cin >> n) {
        memset(adj, 0, sizeof adj);
        for(int i = 0; i < n; i++) {
            int nu;
            cin >> nu;
            while(nu--) {
                int x;
                cin >> x;
                x--;
                adj[i][x] = adj[x][i] = 1;
            }
        }
        for(int msk = 0; msk < (1 << n); msk++) {
            ind[msk] = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if((msk & (1 << i)) && (msk & (1 << j)) && adj[i][j])
                        ind[msk] = false;
                }
            }
        }
        memset(memo, -1, sizeof memo);
        cout << dp((1 << n) - 1) << '\n';
    }
}



