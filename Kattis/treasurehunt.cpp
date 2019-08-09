#include <bits/stdc++.h>
using namespace std;

char board[205][205];
bool seen[205][205];
map<char, pair<int, int>> mp;

int main() {
    mp['E'] = {0, 1};
    mp['W'] = {0, -1};
    mp['S'] = {1, 0};
    mp['N'] = {-1, 0};
    int x = 1, y = 1;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    int st = 0;
    while(true) {
        if(seen[x][y]) {
            cout << "Lost\n";
            return 0;
        }
        if(x <= 0 || y <= 0 || x > n || y > m) {
            cout << "Out\n";
            return 0;
        }
        seen[x][y] = true;
        if(board[x][y] == 'T') {
            cout << st << endl;
            return 0;
        }
        auto p = mp[board[x][y]];
        x += p.first;
        y += p.second;
        st++;
    }
}