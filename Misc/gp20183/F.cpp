#include <bits/stdc++.h>
using namespace std;

struct itv {
    int st, en, val, kind;
    bool operator< (const itv &o) const { return en < o.en; }
};

int best[1005], dp[1005][1 << 10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<itv> segs;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while(k--) {
            int st, en, val;
            cin >> st >> en >> val;
            segs.push_back(itv{st, en, val, i});
        }
    }
    sort(segs.begin(), segs.end());
    //for(auto seg : segs)
    //    cout << "[" << seg.st << " " << seg.en << "]" << endl;
    memset(best, -1, sizeof best);
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < segs.size(); i++) {
        auto it = lower_bound(segs.begin(), segs.end(), itv{segs[i].st + 1, segs[i].st + 1, 0, 0});
        if(it == segs.begin())
            continue;
        --it;
        best[i + 1] = distance(segs.begin(), it) + 1;
    }
    //for(int i = 1; i <= segs.size(); i++)
    //    cout << best[i] << endl;
    dp[0][0] = 0;
    for(int i = 1; i <= segs.size(); i++) {
        int t = segs[i - 1].kind, v = segs[i - 1].val;
        for(int msk = 0; msk < (1 << n); msk++) {
            // No tomar
            dp[i][msk] = dp[i - 1][msk];
            // Sí tomar
            if(msk & (1 << t)) {
                if(best[i] == -1) {
                    if(msk == (1 << t))
                        dp[i][msk] = v;
                }
                else {
                    if(dp[best[i]][msk] >= 0)
                        dp[i][msk] = max(dp[i][msk], v + dp[best[i]][msk]);
                    if(dp[best[i]][msk ^ (1 << t)] >= 0)
                        dp[i][msk] = max(dp[i][msk], v + dp[best[i]][msk ^ (1 << t)]);
                }
            }
            //cout << i << " " << msk << " " << dp[i][msk] << endl;
        }
    }
    cout << dp[segs.size()][(1 << n) - 1] << endl;
}