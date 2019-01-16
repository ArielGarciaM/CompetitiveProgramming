#include <bits/stdc++.h>
using namespace std;

char board[100][100];

int main() {
    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            board[i][j] = (i < 50 ? '@' : '.');
        }
    }
    int b, w;
    cin >> b >> w;
    int x = 0, y = 0;
    while(w > 1) {
        board[x][y] = '.';
        y += 2;
        if(y == 100) {
            y = 0;
            x += 2;
        }
        w--;
    }
    x = 99, y = 0;
    while(b > 1) {
        board[x][y] = '@';
        y += 2;
        if(y == 100) {
            y = 0;
            x -= 2;
        }
        b--;
    }
    cout << "100 100\n";
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++)
            cout << board[i][j];
        cout << '\n';
    }
}