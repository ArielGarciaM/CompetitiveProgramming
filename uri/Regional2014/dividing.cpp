#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
const int INF = 1e9;
int to[MAXN][26], cnt[MAXN], len[MAXN], dp[MAXN][105], pref[26][105], ct = 1;
bool term[MAXN];

void add_word(string s) {
    int cur = 0, l = 1;
    for(auto c : s) {
        if(to[cur][c - 'A'] == -1) {
            to[cur][c - 'A'] = ct++;
            len[to[cur][c - 'A']] = l;
        }
        cur = to[cur][c - 'A'];
        l++;
    }
    term[cur] = true;
}

void dfs(int s = 0) {
    if(term[s]) cnt[s] = 1;
    for(int i = 0; i < 26; i++) {
        if(to[s][i] == -1) continue;
        dfs(to[s][i]);
        cnt[s] += cnt[to[s][i]];
    }
}

void calc(int s = 0) {
    for(int i = 0; i < 26; i++) {
        if(to[s][i] == -1) continue;
        calc(to[s][i]);
    }
    for(int st = 0; st <= cnt[s]; st++) {
        int ave = cnt[s] - st;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < MAXN; i++)
        fill(to[i], to[i] + 26, -1);
    for(int i = 0; i < 2*n; i++) {
        string s;
        cin >> s;
        add_word(s);
    }
    dfs();
}