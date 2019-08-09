#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int cost[100][100];

void floyd() {
    for(int k = 0; k < 100; k++) {
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

int main() {
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(i != j)
                cost[i][j] = INF;
        }
    }
    string s, t;
    cin >> s >> t;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        int u = a - 33, v = b - 33;
        cost[u][v] = min(cost[u][v], c);
    }
    floyd();
    /*for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(cost[i][j] < INF) {
                cout << (char)(i + 33) << " " << (char)(j + 33) << " " << cost[i][j] << endl;
            }
        }
    }*/
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        if(cost[s[i] - 33][t[i] - 33] == INF) {
            cout << -1 << endl;
            return 0;
        }
        ans += cost[s[i] - 33][t[i] - 33];
    }
    cout << ans << endl;
}