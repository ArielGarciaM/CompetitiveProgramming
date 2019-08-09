#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int gdy[MAXN][MAXN];

void calc(int i, int j) {
    vector<int> ct(500);
    for(int k = j - 1; k >= 0; k--) ct[gdy[i][k]]++;
    for(int k = i - 1; k >= 0; k--) ct[gdy[k][j]]++;
    for(int k = 1; k <= min(i, j); k++) ct[gdy[i - k][j - k]]++;
    for(int k = 0; k < 500; k++) {
        if(ct[k] == 0) {
            gdy[i][j] = k;
            return; 
        }
    }
}

int main() {
    for(int i = 1; i < MAXN; i++)
        gdy[i][0] = gdy[0][i] = gdy[i][i] = 400;

    for(int i = 1; i < MAXN; i++) {
        for(int j = 1; j < MAXN; j++) {
            if(i != j) calc(i, j);
        }
    }

    int res = 0;
    int n;
    cin >> n;
    while(n--) {
        int r, c;
        cin >> r >> c;
        res ^= gdy[r][c];
    }
    cout << (res ? "Y" : "N") << '\n';
}