#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

set<ii> bad;
map<ii, int> dis;
queue<ii> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m, t, ans = 0;
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        q.push({x, y});
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        bad.insert({x, y});
    }
    ans = n;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        if(dis[p] == t) continue;
        for(int i = 0; i < 4; i++) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(bad.count({nx, ny})) continue;
            if(!dis.count({nx, ny})) {
                ans++;
                q.push({nx, ny});
                dis[{nx, ny}] = dis[p] + 1;
            }
        }
    }
    cout << ans << '\n';
}