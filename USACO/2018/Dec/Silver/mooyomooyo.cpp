#include <bits/stdc++.h>
using namespace std;

char board[102][10];
int n, k, vist[102][10];
vector<pair<int, int>> comp, dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void printBoard() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void dfs(int i, int j, char d) {
    vist[i][j] = 1;
    //cout << "visited (" << i << ", " << j << ")\n";
    comp.push_back({i, j});
    for(auto v : dir) {
        int ni = i + v.first, nj = j + v.second;
        if(ni < 0 || ni >= n || nj < 0 || nj >= 10)
            continue;
        if(board[ni][nj] == d && !vist[ni][nj])
            dfs(ni, nj, d);
    }
}

bool oper() {
    bool ret = false, zero;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            vist[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            if(board[i][j] == '0')
                continue;
            if(!vist[i][j]) {
                dfs(i, j, board[i][j]);
                zero = false;
                if(comp.size() >= k) {
                    zero = ret = true;
                }
                while(!comp.empty()) {
                    if(zero) {
                        pair<int, int> p = comp.back();
                        board[p.first][p.second] = '0';
                    }
                    comp.pop_back();
                }
                //printBoard();
            }
        }
    }
    return ret;
}

void fall() {
    for(int j = 0; j < 10; j++) {
        int fPos = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(board[i][j] != '0') {
                board[fPos][j] = board[i][j];
                if(fPos != i)
                    board[i][j] = '0';
                fPos--;
            }
        }
    }
}

int main(){
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 10; j++) {
            board[i][j] = s[j];
        }
    }
    while(oper()) {
        fall();
    }
    printBoard();
}