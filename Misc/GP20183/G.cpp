#include <bits/stdc++.h>
using namespace std;

const int MAX = 4005;
const long long INF = 1e16;
int nodes, src, dst;
int dist[MAX], q[MAX], work[MAX];

struct Edge
{
	int to, rev;
	long long f, cap;
	Edge(int to, int rev, long long f, long long cap) : to(to), rev(rev), f(f), cap(cap){}
};
vector<Edge> G[MAX];

void addEdge(int s, int t, long long cap)
{
	G[s].push_back(Edge(t, G[t].size(), 0, cap));
	G[t].push_back(Edge(s, G[s].size() - 1, 0, 0));
}

bool dinic_bfs()
{
	cout << "lel\n";
	fill(dist, dist + nodes, -1);
	dist[src] = 0;
	int qt = 0;
	q[qt++] = src;
	for(int qh = 0; qh < qt; qh++)
	{
		int u = q[qh];
		for(auto e = G[u].begin(); e != G[u].end(); ++e)
		{
			int v = e->to;
			if(dist[v]<0 && e->f < e->cap)
			{
				dist[v] = dist[u]+1;
				q[qt++] = v;
			}
		}
	}
	return dist[dst]>= 0;
}

long long dinic_dfs(int u, long long f)
{
	if(u == dst) return f;
	for(int &i = work[u]; i < G[u].size(); i++)
	{
		Edge &e = G[u][i];
		if(e.cap <= e.f) continue;
		int v = e.to;
		if(dist[v] == dist[u] + 1)
		{
			long long df = dinic_dfs(v, min(f, e.cap - e.f));
			if(df > 0)
			{
				e.f += df;
				G[v][e.rev].f -= df;
				return df;
			}
		}
	}
	return 0;
}

long long maxFlow(int _src, int _dst)
{
	src = _src;
	dst = _dst;
	long long result = 0;
	while(dinic_bfs())
	{
		fill(work, work + nodes, 0);
		while(long long delta = dinic_dfs(src, INF))
			result += delta;
	}
	return result;
}

int main()
{
	int P, R, C;
	cin >> P >> R >> C;
	int D[2005], E[2005];
	for(int i = 0; i < P; i++)
		cin >> D[i];
	for(int i = 0; i < R; i++)
		cin >> E[i];
	long long target = 0;
	for(int i = 0; i < P; i++)
		target += D[i];
	int source = R + P, sink = R + P + 1;
	for(int i = 0; i < C; i++)
	{
		int r, p, wt;
		cin >> r >> p >> wt;
		cout << p - 1 << " " << R + r - 1 << " " << 10000000 << endl;
		addEdge(p - 1, R + r - 1, 10000000);
	}
	for(int i = 0; i < R; i++)
	{
		addEdge(source, i, E[i]);
		cout << source << " " << i << " " << E[i] << endl;
	}
	for(int i = 0; i < P; i++)
	{
		addEdge(R + i, sink, D[i]);
		cout << R + i << " " << sink <<  " " << D[i] << endl;
	}
	cout << "All cool\n";
	if(maxFlow(source, sink) == target) cout << "Good\n";
	else cout << -1 << endl;
}