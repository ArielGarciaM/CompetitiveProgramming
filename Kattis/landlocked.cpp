#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
const int INF = 1e9;

int main() {
    int ans[26], dist[1001][1001];
    memset(ans, -1, sizeof(ans));
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++)
            dist[i][j] = INF;
    }
    char board[1001][1001];
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, pair<int, int>>> pq;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            board[i][j] = s[j];
            if(s[j] == 'W') {
                dist[i][j] = 0;
                pq.push(make_pair(0, make_pair(i, j)));
            }
        }
    }
    while(!pq.empty()) {
        auto p = pq.top().second;
        int i = p.first, j = p.second;
        char c = board[i][j];
        if(c != 'W') {
            if(dist[i][j] < ans[c - 'A'] || ans[c - 'A'] == -1)
                ans[c - 'A'] = dist[i][j];
        }
        pq.pop();
        for(auto d : dir) {
            int ni = i + d.first, nj = j + d.second;
            if(ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;
            int nd = (board[i][j] == board[ni][nj] ? 0 : 1);
            if(dist[ni][nj] > dist[i][j] + nd) {
                dist[ni][nj] = dist[i][j] + nd;
                pq.push(make_pair(-dist[ni][nj], make_pair(ni, nj)));
            }
        }
    }
    for(int i = 0; i < 26; i++) {
        if(i == 22)
            continue;
        if(ans[i] != -1)
            cout << (char)('A' + i) << " " << ans[i] - 1 << endl;
    }
}
