#include <bits/stdc++.h>
using namespace std;

const int MAXP = 17;
const int INF = 1e9;

int good[MAXP][MAXP], vis[MAXP][MAXP][1<<MAXP], bad[1 << MAXP];
int memo[1<<MAXP], cnt[MAXP], n, p;
queue<int> q[MAXP][MAXP];

int dp(int mask) {
    if(memo[mask] != -1)
        return memo[mask];
    if(bad[mask])
        return memo[mask] = INF;
    int x = 0;
    for(int i = 0; i < p; i++)
        if(mask & (1 << i))
            x += cnt[i];
    memo[mask] = x;
    for(int i = 0; i < p; i++) {
        if(mask & (1 << i))
            memo[mask] = min(memo[mask], dp(mask ^ (1 << i)));
    }
    return memo[mask];
}

void bfs(int i, int j) {
    while(!q[i][j].empty()) {
        int ma = q[i][j].front();
        q[i][j].pop();
        bad[ma] = 1;
        for(int k = 0; k < p; k++) {
            if(k == i || k == j)
                continue;
            if(ma & (1 << k)) {
                int mo = ma ^ (1 << k);
                if(!vis[i][j][mo]) {
                    q[i][j].push(mo);
                    vis[i][j][mo] = 1;
                }
            }
        }
    }
}

int main() {
    string s;
    cin >> n >> p;
    cin >> s;

    for(int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;

    for(int i = 0; i < p; i++)
        for(int j = 0; j < p; j++)
            cin >> good[i][j];

    for(int i = 0; i < p; i++) {
        int ps = 0;
        while(s[ps] != 'a' + i)
            ++ps;
        int ma = 0;
        for(++ps;ps < n; ps++) {
            int d = s[ps] - 'a';
            if(!good[i][d] || (ma & (1 << d) == 0)) {
                int oms = ((1 << p) - 1 - ma);
                if(!vis[i][d][oms]) {
                    //cout << i << " " << d << " " << oms << endl;
                    q[i][d].push(oms);
                    vis[i][d][oms] = 1;
                }
            }
            if(d == i)
                ma = 0;
            else
                ma |= (1 << d);
            //cout << ma << " ";
        }
        //cout << endl;
    }

    for(int i = 0; i < p; i++)
        for(int j = 0; j < p; j++)
            bfs(i, j);

    memset(memo, -1, sizeof memo);
    cout << dp((1 << p) - 1) << endl;
}