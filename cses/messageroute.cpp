#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int dis[MAXN], pre[MAXN];

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q({1});
	memset(dis, -1, sizeof dis);
	dis[1] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto v : adj[u]) {
			if(dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
				pre[v] = u;
			}
		}
	}
	if(dis[n] == -1) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vector<int> route;
	int u = n;
	while(u != 1) {
		route.push_back(u);
		u = pre[u];
	}
	route.push_back(1);
	reverse(route.begin(), route.end());
	cout << route.size() << '\n';
	for(auto x : route)
		cout << x << " ";
	cout << '\n';
}
