#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 3;
vector<int> adj[MAXN];
int color[MAXN];

int bfs(int s)
{
    int fcol = 1, scol = 0;
    color[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : adj[u])
        {
            if(color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
                if(color[v] == 0)
                    fcol++;
                else
                    scol++;
            }
        }
    }
    return min(fcol, scol);
}

int main()
{
    vector<pair<int, int>> dir;
    set<pair<int, int>> pts;
    map<pair<int, int>, int> mp;
    for(int i = -5; i <= 5; i++)
    {
        for(int j = -5; j <= 5; j++)
        {
            if(i*i + j*j <= 25)
                dir.push_back({i, j});
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[{x, y}] = i;
        pts.insert({x, y});
    }
    for(auto p : pts)
    {
        int x = p.first, y = p.second;
        for(auto d : dir)
        {
            int dx = d.first, dy = d.second;
            if(pts.count({x + dx, y + dy}))
            {
                adj[mp[{x, y}]].push_back(mp[{x + dx, y + dy}]);
            }
        }
    }
    int ans = 0;
    memset(color, -1, sizeof(color));
    for(int i = 0; i < n; i++)
    {
        if(color[i] == -1)
            ans += bfs(i);
    }
    cout << ans << endl;
}