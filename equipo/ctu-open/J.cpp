#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 2;
int lev[MAXN], order[MAXN], oind = 0;
vector<int> adj[20*MAXN], ladj[MAXN];
vector<pair<int, int>> ed;
bitset<MAXN> vist;
long long cnt[20], sz, va;

void ldfs(int s, int p = -1) {
    lev[s] = (p == -1 ? 0 : lev[p] + 1);
    order[oind++] = s;
    for(auto v : ladj[s]) {
        if(v == p)
            continue;
        ldfs(v, s);
    }
}

void dfs(int src, int off)
{
    vist.set(src);
    va += sz++;
    for(auto v : adj[off + src])
        dfs(v, off);
}

int main()
{
    int n, val[MAXN], pt[20];
    long long ans;
    scanf("%d", &n);
    for(int i = 0; i < 20; i++)
        pt[i] = (1 << i);
    for(int i = 0; i < n; i++)
        scanf("%d", &val[i]);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        ladj[u].push_back(v);
        ladj[v].push_back(u);
        ed.push_back({u, v});
        /*int x = val[u] & val[v];
        for(int j = 0; j < 20; j++)
        {
            if(x & pt[j])
            {
                //adj[j*MAXN + u].push_back(v);
                //adj[j*MAXN + v].push_back(u);
            }
        }*/
    }
    ldfs(0);
    for(auto p : ed) {
        int u = p.first, v = p.second, x = val[u] & val[v];
        for(int j = 0; j < 20; j++)
        {
            if(x & pt[j])
            {
                if(lev[u] < lev[v])
                    adj[j*MAXN + u].push_back(v);
                else
                    adj[j*MAXN + v].push_back(u);
            }
        }
    }
    for(int g = 0; g < 20; g++)
    {
        vist.reset();
        long long p = pt[g];
        for(int j = 0; j < n; j++)
        {
            int i = order[j];
            if(vist[i] || !(val[i] & p))
                continue;
            va = sz = 0;
            dfs(i, g*MAXN);
            ans += p*(va + sz);
        }
    }
    cout << ans << endl;
}