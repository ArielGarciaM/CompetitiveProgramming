#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int MAXN = 20, INF = 1e9;;
int dp[1 << MAXN];
vector<ii> p[MAXN];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for(int j = 0; j < num; j++) {
            int l, k;
            cin >> l >> k;
            int msk = 0;
            while(k--) {
                int d;
                cin >> d;
                msk |= (1 << d);
            }
            p[i].push_back({msk, l});
        }
    }
    dp[0] = 0;
    for(int msk = 1; msk < (1 << n); msk++) {
        dp[msk] = INF;
        for(int b = 0; b < n; b++) {
            if((msk & (1 << b)) == 0)
                continue;
            int sm = msk ^ (1 << b);
            for(auto proof : p[b]) {
                int nmsk = proof.first, cst = proof.second;
                if((nmsk & sm) == nmsk)
                    dp[msk] = min(dp[msk], dp[sm] + cst);
            }
        }
    }
    int ans = INF;
    for(int i = 1; i < (1 << n); i += 2)
        ans = min(ans, dp[i]);
    cout << ans << endl;
}