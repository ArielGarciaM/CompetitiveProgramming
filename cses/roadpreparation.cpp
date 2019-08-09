#include <bits/stdc++.h>
using namespace std;

vector<int> rep;
vector<array<int, 3>> edges;
int comps;

void init() {
	fill(rep.begin(), rep.end(), -1);
}

int find(int u) {
	return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}

bool join(int u, int v) {
	u = find(u), v = find(v);
	if(u == v) return false;
	rep[v] = u;
	return true;
}

long long kruskal() {
	long long res = 0;
	sort(edges.begin(), edges.end());
	for(auto e : edges) {
		if(join(e[1], e[2])) {
			res += e[0];
			comps--;
		}
	}
	if(comps > 1)
		return -1;
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	rep.resize(n + 1);
	comps = n;
	init();
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, u, v});
	}
	long long ans = kruskal();
	if(ans == -1)
		cout << "IMPOSSIBLE\n";
	else
		cout << ans << '\n';
}
