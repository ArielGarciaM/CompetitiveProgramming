#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 10;
int evs[MAXN];
vector<ii> edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    if(m % 2) {
        cout << "-1\n";
        return 0;
    }

    random_shuffle(edges.begin(), edges.end());

    for(int i = 0; i < m; i++)
        evs[edges[i].first]++;

    for(int i = 0; i < m; i++) {
        int u = edges[i].first, v = edges[i].second;
        if(evs[u] % 2 == 0) continue;
        evs[u]--;
        evs[v]++;
        edges[i] = {v, u};
    }

    for(int i = 0; i < m; i++)
        cout << edges[i].first << " " << edges[i].second << '\n';
}