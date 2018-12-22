#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int msk[9];
vector<int> vist, dist;

int bfs(int src, int dst)
{
    vist.assign(2000, 0);
    dist.assign(2000, 0);
    vist[src] = 1;
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == dst)
            return dist[u];
        for(int i = 0; i < 9; i++)
        {
            int v = u ^ msk[i];
            if(!vist[v])
            {
                q.push(v);
                vist[v] = 1;
                dist[v] = dist[u] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<pii> dir = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for(int i = 0; i < 9; i++)
    {
        int q = i/3, r = i%3;
        for(auto d : dir)
        {
            int nq = q + d.first, nr = r + d.second;
            if(nq < 0 || nq > 2 || nr < 0 || nr > 2)
                continue;
            msk[i] += (1 << (3*nq + nr));
        }
    }
    /*for(int i = 0; i < 9; i++)
    {
        int x = msk[i];
        while(x > 0)
        {
            cout << (x%2);
            x /= 2;
        }
        cout << endl;
    }*/
    int p;
    cin >> p;
    for(int i = 0; i < p; i++)
    {
        int target = 0;
        int j = 0, k = 0;
        string s;
        for(int t = 0; t < 3; t++)
        {
            cin >> s;
            for(k = 0; k < 3; k++, j++)
                target += (s[k] == '*' ? (1 << j) : 0);
        }
        int x = target;
        /*while(x > 0)
        {
            cout << (x%2);
            x /= 2;
        }
        cout << endl;*/
        cout << bfs(0, target) << endl;
    }
}