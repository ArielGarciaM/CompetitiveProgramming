#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int INF = 301;
const int MAX = 1e5 + 5;
const int MAXL = 5e5 + 5;
const ll MOD = 1e9 + 7;

int s[MAXL], SA[MAXL], val[MAXL], cnt[MAXL], pos[MAXL], n;

void csort(int l) {
    int mx = max(305, n), sum = 0, tSA[MAXL];
    fill(cnt, cnt + mx, 0);
    for(int i = 0; i < n; i++)
        cnt[(SA[i] + l < n) ? val[SA[i] + l] : 0]++;
    for(int i = 0; i < mx; i++)
        {int t = cnt[i]; cnt[i] = sum; sum += t;}
    for(int i = 0; i < n; i++)
        tSA[cnt[SA[i] + l < n ? val[SA[i] + l] : 0]++] = SA[i];
    for(int i = 0; i < n; i++)
        SA[i] = tSA[i];
}

void buildSA() {
    int nval[MAXL], rk, l = 1;
    iota(SA, SA + n, 0);
    for(int i = 0; i < n; i++)
        val[SA[i]] = s[i];
    do {
        csort(l);
        csort(0);
        nval[SA[0]] = rk = 0;
        for(int i = 1; i < n; i++) nval[SA[i]] =
            ii{val[SA[i]], val[SA[i] + l]} == ii{val[SA[i - 1]], val[SA[i - 1] + l]} ? rk:++rk;
        for(int i = 0; i < n; i++)
            val[i] = nval[i];
        l <<= 1;
    } while(val[SA[n - 1]] != n - 1 && l < n);
}

struct marb {
    int val, lex, idx;
    bool operator< (const marb& o) const { return tie(val, lex) > tie(o.val, o.lex); }
};

vector<int> v[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m;
    n = 0;
    cin >> m;
    priority_queue<marb> pq;
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        v[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> v[i][j];
            s[n++] = v[i][j];
        }
        s[n++] = INF;
    }
    buildSA();
    for(int i = 0; i < n; i++)
        pos[SA[i]] = i;
    for(int i = 0; i < n; i++) {
        if(i == 0 || s[i - 1] == INF)
            pq.push({s[i], pos[i], i});
    }
    ll ans = 0;
    while(!pq.empty()) {
        marb m = pq.top(); pq.pop();
        ans = (365ll*ans + (ll)m.val)%MOD;
        if(s[m.idx + 1] != INF)
            pq.push({s[m.idx + 1], pos[m.idx + 1], m.idx + 1});
    }
    cout << (365ll*ans)%MOD << endl;
}