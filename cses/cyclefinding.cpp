#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
vector<vector<pair<int, ll>>> adj;
vector<ll> dis;
vector<int> prv;

int main() {
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1), dis.resize(n + 1, INF), prv.resize(n + 1);
	while(m--) {
		int x, y;
		ll w;
		cin >> x >> w >> y;
		adj[x].push_back({w, y});
	}
	int last = 0;
	dis[1] = 0;
	for(int it = 0; it < n; it++) {
		last = 0;
		for(int u = 1; u <= n; u++) {
			for(auto p : adj[u]) {
				int v = p.first;
				ll w = p.second;
				if(dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					prv[v] = u;
					last = v;
				}
			}
		}
	}
	if(last == 0) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int u = last, v = u;
	for(int i = 0; i < n; i++)
		v = prv[v];
	u = v;
	v = prv[v];
	vector<int> ans;
	ans.push_back(u);
	while(v != u) {
		ans.push_back(v);
		v = prv[v];
	}
	ans.push_back(u);
	reverse(ans.begin(), ans.end());
	for(auto v : ans)
		cout << v << " ";
	cout << '\n';
}
