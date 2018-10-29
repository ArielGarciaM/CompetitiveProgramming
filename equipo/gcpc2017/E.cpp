#include<bits/stdc++.h>
using namespace std;

const int MAXN = 801;
const double INF = 1e9;
const double eps = 1e-7;
int N, M;
vector<pair<double, int>> G[MAXN];
double dist[MAXN];

void bford(int s)
{
    dist[s] = 0;
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(abs(dist[j] - INF) > eps)
            {
                for(auto p : G[j])
                    dist[p.second] = min(dist[p.second], dist[j] + p.first);
            }
        }
    }
}

bool hasNegCycle()
{
    for(int j = 0; j < N; j++)
    {
        if(abs(dist[j] - INF) > eps)
        {
            for(auto p : G[j])
            {
                if(dist[p.second] > dist[j] + p.first + eps)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    for(int i = 0; i < MAXN; i++)
    {
        dist[i] = INF;
    }
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int x, y;
        double d;
        cin >> x >> y >> d;
        double w = -1.0*log(d);
        G[x - 1].push_back(make_pair(w, y - 1));
    }
    for(int i = 0; i < N; i++)
    {
        if(abs(dist[i] - INF) < eps)
            bford(i);
    }
    if(hasNegCycle())
        cout << "inadmissible\n";
    else
        cout << "admissible\n";
}