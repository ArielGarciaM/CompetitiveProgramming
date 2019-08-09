#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int MAX = 39;
int dist[MAX][MAX];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs() {
    queue<ii> q;
    q.push({19, 19});
    dist[19][19] = 0;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= MAX || ny < 0 || ny >= MAX || dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}

ll ans(ll x, ll y) {
    if(x < 0)
        x *= -1;
    if(y < 0)
        y *= -1;
    if(y > x)
        swap(x, y);
    if(x == 0 && y == 0)
        return 0;
    if(x == 1 && y == 0)
        return 3;
    if(x == 1 && y == 1)
        return 2;
    if(x == 2 && y == 2)
        return 4;
    if(2*y > x) {
        // 2*(y - 2d) <= x - d
        // 2y - x <= 3d
        // d >= (2y - x)/3
        ll d = (2ll*y - x + 2ll)/3ll;
        return d + ans(y - 2*d, x - d);
    }
    else {
        ll base = (x/2ll) + 1;
        if(x % 4 == 0 && y % 2 == 0) base--;
        if(x % 4 == 1 && y % 2) base++;
        if(x % 4 == 2 && y % 2) base--;
        if(x % 4 == 3 && y % 2 == 0) base++;
        return base;
    }
}

int main() {
    ll m, n, p, q, r, s;
    cin >> m >> n >> p >> q >> r >> s;
    if(p == 0 && q == 0 && r == 1 && s == 1) {
        cout << "4\n";
        return 0;
    }
    if(p == m - 1 && q == n - 1 && r == m - 2 && s == n - 2) {
        cout << "4\n";
        return 0;
    }
    if(p == 1 && q == 1 && r == 0 && s == 0) {
        cout << "4\n";
        return 0;
    }
    if(p == m - 2 && q == n - 2 && r == m - 1 && s == n - 1) {
        cout << "4\n";
        return 0;
    }
    if(p == m - 1 && q == 0 && r == m - 2 && s == 1) {
        cout << "4\n";
        return 0;
    }
    if(p == m - 2 && q == 1 && r == m - 1 && s == 0) {
        cout << "4\n";
        return 0;
    }
    if(p == 0 && q == n - 1 && r == 1 && s == n - 2) {
        cout << "4\n";
        return 0;
    }
    if(p == 1 && q == n - 2 && r == 0 && s == n - 1) {
        cout << "4\n";
        return 0;
    }
    r -= p;
    s -= q;
    cout << ans(r, s) << endl;
}