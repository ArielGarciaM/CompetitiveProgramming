#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int rep[MAXN];

void init() {
	fill(rep, rep + MAXN, -1);
}

int find(int u) {
	return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
	u = find(u), v = find(v);
	if(u == v) return;
	rep[v] = u;
}

int main() {
	
	init();
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		join(u, v);
	}
	vector<pair<int, int>> ans;
	for(int v = 2; v <= n; v++) {
		int u = find(1), x = find(v);
		if(u != x) {
			ans.push_back({u, x});
			join(u, x);
		}
	}
	cout << ans.size() << '\n';
	for(auto p : ans)
		cout << p.first << " " << p.second << '\n';
}
