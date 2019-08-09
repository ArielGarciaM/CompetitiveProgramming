#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int n;
char board[2050][2050];
bool seen[26];
vector<ii> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void place(vector<ii> v) {
    memset(seen, false, sizeof seen);
    for(auto p : v) {
        for(auto d : dir) {
            int nr = p.first + d.first, nc = p.second + d.second;
            if(nr < 1 || nr > n || nc < 1 || nc > n)
                continue;
            if(board[nr][nc] >= 'A' && board[nr][nc] <= 'Z')
                seen[board[nr][nc] - 'A'] = true;
        }
    }
    int i = 0;
    while(seen[i])
        i++;
    char c = 'A' + i;
    for(auto p : v)
        board[p.first][p.second] = c;
}

void solve(int sr, int er, int sc, int ec, int r, int c) {
    if(sr == er)
        return;
    int mr = (sr + er)/2, mc = (sc + ec)/2;
    if(r <= mr) {
        if(c <= mc) {
            solve(sr, mr, sc, mc, r, c);
            solve(mr + 1, er, sc, mc, mr + 1, mc);
            solve(sr, mr, mc + 1, ec, mr, mc + 1);
            solve(mr + 1, er, mc + 1, ec, mr + 1, mc + 1);
            place({{mr + 1, mc}, {mr, mc + 1}, {mr + 1, mc + 1}});
        }
        else {
            solve(sr, mr, sc, mc, mr, mc);
            solve(mr + 1, er, sc, mc, mr + 1, mc);
            solve(sr, mr, mc + 1, ec, r, c);
            solve(mr + 1, er, mc + 1, ec, mr + 1, mc + 1);
            place({{mr, mc}, {mr + 1, mc}, {mr + 1, mc + 1}});
        }
    }
    else {
        if(c <= mc) {
            solve(sr, mr, sc, mc, mr, mc);
            solve(mr + 1, er, sc, mc, r, c);
            solve(sr, mr, mc + 1, ec, mr, mc + 1);
            solve(mr + 1, er, mc + 1, ec, mr + 1, mc + 1);
            place({{mr, mc}, {mr, mc + 1}, {mr + 1, mc + 1}});
        }
        else {
            solve(sr, mr, sc, mc, mr, mc);
            solve(mr + 1, er, sc, mc, mr + 1, mc);
            solve(sr, mr, mc + 1, ec, mr, mc + 1);
            solve(mr + 1, er, mc + 1, ec, r, c);
            place({{mr, mc}, {mr + 1, mc}, {mr, mc + 1}});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> n >> r >> c;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            board[i][j] = '_';
        }
    }
    board[r][c] = '.';
    solve(1, n, 1, n, r, c);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}