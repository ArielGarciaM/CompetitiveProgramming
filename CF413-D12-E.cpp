#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;
const int MAXV = 2*MAXN;
const int INF = 1e6;
vector<int> adj[MAXN];
vector<int> vist(MAXN);

int bfs(int s, long long iwt, vector<long long> &dist)
{
    queue<int> q;
    q.push(s);
    vist[s] = 1;
    dist[s] = iwt;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : adj[u])
        {
            if(!vist[v])
            {
                dist[v] = dist[u] + 1;
                vist[v] = 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, m, fstTop = INF, fstBot = INF;
    cin >> n >> m;
    vector<int> xtop, xbot;
    xtop.push_back(-1);
    xbot.push_back(-1);
    char rect[2][MAXN];
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        rect[0][i] = s[i];
        if(s[i] == 'X')
            xtop.push_back(i);
        else
            fstTop = min(fstTop, i);
    }
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        rect[1][i] = s[i];
        if(s[i] == 'X')
            xbot.push_back(i);
        else
            fstBot = min(fstBot, i);
    }
    xbot.push_back(n);
    xtop.push_back(n);
    for(int i = 0; i < n; i++)
    {
        if(i < n - 1)
        {
            if(rect[0][i] == '.' && rect[0][i + 1] == '.')
            {
                adj[i].push_back(i + 1);
                adj[i + 1].push_back(i);
            }
            if(rect[1][i] == '.' && rect[1][i + 1] == '.')
            {
                adj[n + i].push_back(n + i + 1);
                adj[n + i + 1].push_back(n + i);
            }
        }
        if(rect[0][i] == '.' && rect[1][i] == '.')
        {
            adj[i].push_back(n + i);
            adj[n + i].push_back(i);
        }
    }
    vector<long long> dTop(MAXN), dBot(MAXN);
    long long wt = 0;
    for(int i = 0; i < n; i++)
    {
        if(rect[0][i] == 'X')
            wt += 2*INF;
        else
        {
            if(!vist[i])
            {
                bfs(i, wt, dTop);
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << dTop[i] << " ";
    cout << endl;
    vist.assign(n, 0);
    wt = 0ll;
    for(int i = 0; i < n; i++)
    {
        if(rect[1][i] == 'X')
            wt += 2*INF;
        else
        {
            if(!vist[n + i])
            {
                bfs(n + i, wt, dBot);
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        long long d;
        if(x < n && y < n)
            d = abs(dTop[x] - dTop[y]);
        else if(x >= n && y >= n)
            d = abs(dBot[x] - dBot[y]);
        else
        {
            // x on top, y on bottom
            if(x > y)
                swap(x, y);
            y -= n;
            int b;
            if(x <= y)
            {
                // Go right from x
                auto it = upper_bound(xtop.begin(), xtop.end(), x);
                b = min(*it - 1, y);
                d = 1 + dTop[b] - dTop[x] + dBot[y + n] - dBot[b + n];
                if(rect[1][b] == 'X')
                    d += INF;
            }
            else
            { 
                // Go right from y
                auto it = upper_bound(xbot.begin(), xbot.end(), y);
                b = min(*it - 1, x);
                d = 1 + dBot[b + n] - dBot[y + n] + dTop[x] - dTop[b];
                if(rect[0][b] == 'X')
                    d += INF;
            }
        }
        cout << (d < INF ? d : -1) << endl;
    }
}