#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e5 + 5;
int winner[MAXS];

int main() {
    memset(winner, -1, sizeof(winner));
    int n, k;
    cin >> n >> k;
    vector<int> st(n);
    for(int i =0; i < n; i++)
        cin >> st[i];
    for(int p = 1; p <= k; p++) {
        for(int i = 0; i < n; i++) {
            if(p - st[i] >= 0 && winner[p - st[i]] == -1)
                winner[p] = 1;
        }
    }
    cout << (winner[k] == 1 ? "First" : "Second") << endl;
}