#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int INF = 1e9;
int n, mcost[MAXN][MAXN], mans[MAXN], cnt[MAXN], mat[MAXN], pref[MAXN][MAXN], mi[MAXN][MAXN], ma[MAXN][MAXN];
bool good[MAXN][MAXN], perfect[MAXN][MAXN];

int cost(int l, int r) {
    if(mcost[l][r] != -1) return mcost[l][r];
    if(!good[l][r]) return mcost[l][r] = INF;
    if(l == r) return mcost[l][r] = 0;
    mcost[l][r] = INF;
    for(int m = 1; m < r; m++) {
        if(!good[l][m] || !good[m + 1][r]) continue;
        int pot = cost(l, m) + cost(m + 1, r);
        //cout << l << " " << m << " " << r << " " << pot << " ";
        int a = mi[l][m], b = mi[m + 1][r];
        pot += (r - m) - (pref[r][a - 1] - pref[m][a - 1]);
        //cout << pot << " ";
        pot += (m - l + 1) - (pref[m][b - 1] - pref[l - 1][b - 1]);
        //cout << pot << '\n';
        mcost[l][r] = min(mcost[l][r], pot);
    }
    return mcost[l][r];
}

int ans(int s) {
    if(mans[s] != -1) return mans[s];
    if(s == n + 1) return mans[s] = 0;
    mans[s] = INF;
    for(int t = s; t <= n; t++) {
        if(!perfect[s][t]) continue;
        //cout << s << " " << t << '\n';
        mans[s] = min(mans[s], cost(s, t) + ans(t + 1));
    }
    return mans[s];
}

void test_case() {
    cin >> n;
    memset(good, false, sizeof good);
    memset(perfect, false, sizeof perfect);
    for(int i = 1; i <= n; i++)
        cin >> mat[i];
    for(int l = 1; l <= n; l++) {
        for(int x = 1; x < MAXN; x++)
            pref[l][x] = pref[l - 1][x] + (mat[l] <= x);
        memset(cnt, 0, sizeof cnt);
        bool sgood = true;
        for(int r = l; r <= n; r++) {
            mi[l][r] = ma[l][r] = mat[r];
            if(r > l) {
                mi[l][r] = min(mi[l][r], mi[l][r - 1]);
                ma[l][r] = max(ma[l][r], ma[l][r - 1]);
            }
            cnt[mat[r]]++;
            if(cnt[mat[r]] > 1)
                sgood = false;
            good[l][r] = sgood;
            if(sgood && mi[l][r] == 1 && ma[l][r] == r - l + 1) {
                perfect[l][r] = true;
                //cout << l << " " << r << " so kawaii *.*\n";
            }
        }
    }
    memset(mcost, -1, sizeof mcost);
    memset(mans, -1, sizeof mans);
    int a = ans(1);
    if(a == INF)
        cout << "IMPOSSIBLE\n";
    else
        cout << a << '\n';
    /*for(int l = 1; l <= n; l++) {
        for(int r = l; r <= n; r++) {
            cout << "(" << l << ", " << r << ") " << cost(l, r) << '\n';
        }
    }*/
}

int main() {
    int t;
    cin >> t;

    while(t--)
        test_case();
}