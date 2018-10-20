#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int n;

struct edge
{
    int u, v;
    double wt;
    edge(int _u = 0, int _v = 0, double _w = 0.0)
    {
        u = _u;
        v = _v;
        wt = _w;
    }
    bool operator<(const edge e)
    {
        return wt < e.wt;
    }
};

int parent[MAXN + 5];

void init()
{
    memset(parent, -1, sizeof(parent));
}

int find(int v)
{
    return parent[v] == -1 ? v : parent[v] = find(parent[v]);
}

void join(int u, int v)
{
    int a = find(u), b = find(v);
    if(a != b)
        parent[a] = b;
}

vector<edge> edges;

double kruskal()
{
    sort(edges.begin(), edges.end());
    double ans = 0.0;
    int chosen = 0;
    init();
    for(edge e : edges)
    {
        if(chosen == n - 1)
            break;
        if(find(e.u) == find(e.v))
            continue;
        join(e.u, e.v);
        chosen++;
        ans += e.wt;
    }
    return ans;
}

int main()
{
    int numt;
    cin >> numt;
    for(int t = 0; t < numt; t++)
    {
        if(t > 0)
        {
            cin.ignore();
            cout << endl;
        }

        edges.clear();
        cin >> n;
        vector<pair<double, double>> pts;
        for(int i = 0; i < n; i++)
        {
            double x, y;
            cin >> x >> y;
            pts.push_back({x, y});
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                edges.push_back(edge(i + 1, j + 1, hypot(pts[i].first - pts[j].first, pts[i].second - pts[j].second)));
            }
        }
        cout << fixed << setprecision(2) << kruskal() << endl;
    }
}