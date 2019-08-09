#include <bits/stdc++.h>
using namespace std;

vector<int> rep, sz;
vector<array<int, 2>> edges;
int comps, mx;

void init() {
	fill(rep.begin(), rep.end(), -1);
	fill(sz.begin(), sz.end(), 1);
}

int find(int u) {
	return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}

bool join(int u, int v) {
	u = find(u), v = find(v);
	if(u == v)
		return false;
	if(sz[u] < sz[v])
		swap(u, v);
	rep[v] = u;
	sz[u] += sz[v];
	mx = max(mx, sz[u]);
	return true;
}

void spanify() {
	for(auto e : edges) {
		if(join(e[0], e[1]))
			comps--;
		cout << comps << " " << mx << '\n';
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	rep.resize(n + 1), sz.resize(n + 1);
	comps = n;
	mx = 1;
	init();
	while(m--) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
	}
	spanify();
}
