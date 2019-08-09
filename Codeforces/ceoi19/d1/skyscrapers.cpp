#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

map<ii, int> mp, dis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    if(t == 2) {
        cout << ":(\n";
        return 0;
    }
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mp[{x, y}] = i + 1;
    }
    priority_queue<ii, vector<ii>, greater<ii>> q;
    dis[(*mp.begin()).first] = 0;
    q.push((*mp.begin()).first);
    vector<int> ans;
    while(!q.empty()) {
        ii b = q.top(); q.pop();
        int x = b.first, y = b.second;
        ans.push_back(mp[{x, y}]);
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(!mp.count({nx, ny})) continue;
            if(dis.count({nx, ny})) continue;
            dis[{nx, ny}] = dis[{x, y}] + 1;
            q.push({nx, ny});
        }
    }
    if(ans.size() < n) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(auto x : ans)
        cout << x << " ";
    cout << '\n';
}