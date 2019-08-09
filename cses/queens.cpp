#include <bits/stdc++.h>
using namespace std;
int col[8], dl[15], dr[15], ans;
char board[8][8];

void uwu(int r) {
    if(r == 8) {
        ans++;
        return;
    }
    for(int c = 0; c < 8; c++) {
        if(board[r][c] == '*' || col[c] || dl[r + c] || dr[(15 + r - c)%15]) continue;
        col[c] = dl[r + c] = dr[(15 + r - c)%15] = 1;
        uwu(r + 1);
        col[c] = dl[r + c] = dr[(15 + r - c)%15] = 0;
    }
}

int main() {
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> board[i][j];
    uwu(0);
    cout << ans << '\n';
}