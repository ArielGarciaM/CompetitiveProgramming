#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

vector<int> seq[8];
char board[1300][1500];

int red(int x) {
    while(x > 3) x -= 6;
    while(x < -2) x += 6;
    return x;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    map<ii, ii> mov = {
        {{0, 1}, {1, 0}},
        {{0, -2}, {0, 1}},
        {{1, 2}, {0, -1}},
        {{1, -1}, {1, 0}},
        {{2, 3}, {-1, -1}},
        {{2, 0}, {0, -1}},
        {{3, -2}, {-1, 1}},
        {{3, 1}, {-1, 0}},
        {{-2, -1}, {0, 1}},
        {{-2, 2}, {-1, 0}},
        {{-1, 0}, {1, 0}},
        {{-1, 3}, {-1, 0}}
    };       

    seq[0] = {0};
    for(int i = 1; i < 8; i++) {
        seq[i] = seq[i - 1];
        for(auto x : seq[i - 1]) seq[i].push_back(red(x + 1));
        for(auto x : seq[i - 1]) seq[i].push_back(red(x - 1));
        for(auto x : seq[i - 1]) seq[i].push_back(x);
    }

    for(int i = 0; i < 1300; i++)
        for(int j = 0; j < 1500; j++)
            board[i][j] = '.';

    bool started = false;
    int n;
    while(cin >> n) {
        if(started) cout << '\n';
        started = true;
        if(n == 0)
            cout << "_" << endl;
        else {
            int r = 1299, c = 0;
            board[r][c] = '_';
            for(int i = 1; i < seq[n].size(); i++) {
                int pv = seq[n][i - 1], cu = seq[n][i];
                auto p = mov[{pv, cu}];
                c = c + p.first, r = r + p.second;
                if(cu == 3 || cu == 0) board[r][c] = '_';
                if(cu == 1 || cu == -2) board[r][c] = '/';
                if(cu == 2 || cu == -1) board[r][c] = '\\';
            }
            int top, right;
            for(top = 0;;top++) {
                bool has = false;
                for(int j = 0; j < 1500; j++)
                    if(board[top][j] != '.') has = true;
                if(has) break;
            }

            for(right = 1499;;right--) {
                bool has = false;
                for(int j = 0; j < 1300; j++)
                    if(board[j][right] != '.') has = true;
                if(has) break;
            }

            for(int i = top; i < 1300; i++) {
                for(int j = 0; j <= right; j++) {
                    cout << board[i][j];
                    board[i][j] = '.';
                }
                cout << '\n';
            }
        }
    }
}