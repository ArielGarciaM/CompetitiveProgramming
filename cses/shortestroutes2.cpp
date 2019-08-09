#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const int MAXN = 505;
ll dis[MAXN][MAXN];

int main() {
	for(int i = 0; i< MAXN; i++) {
		for(int j = 0; j < MAXN; j++){
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	while(m--) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		dis[u][v] = dis[v][u] =  min(dis[u][v], w);
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	while(q--) {
		int a, b;
		cin >> a >> b;
		cout << (dis[a][b] < INF ? dis[a][b] : -1)  << '\n';
	}
}
