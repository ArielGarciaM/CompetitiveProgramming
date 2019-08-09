#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int col[MAXN];
bool fuck;

void dfs(int s, int c = 1) {
	col[s] = c;
	for(auto v : adj[s]) {
		if(col[v] == col[s]) {
			fuck = true;
			return;
		}
		if(col[v] == 0)
			dfs(v, 3 - c);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	fuck = false;
	for(int u = 1; u <= n; u++)
		if(!col[u]) dfs(u);

	if(fuck) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	for(int i = 1; i <= n; i++)
		cout << col[i] << " ";
	cout << '\n';
}
