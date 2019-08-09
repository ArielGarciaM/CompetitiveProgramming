#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int dist[100];

void bfs(int s) {
    memset(dist, -1, sizeof dist);
    queue<int> q({s});
    dist[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        int r = u/8, c = u % 8;
        for(int d = 0; d < 8; d++) {
            int nr = r + dx[d], nc = c + dy[d];
            if(nr < 0 || nr > 7 || nc < 0 || nc > 7)
                continue;
            int v = 8*nr + nc;
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int r, c, k, ans = 0;
        cin >> r >> c >> k;
        r--, c--;
        bfs(8*r + c);
        for(int i = 0; i < 64; i++)
            if(dist[i] <= k)
                ans++;
        cout << ans << endl;
    }
}