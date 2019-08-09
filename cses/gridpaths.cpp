#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
map<char, ii> dir = {{'U', {-1, 0}}, {'D', {1, 0}}, {'R', {0, 1}}, {'L', {0, -1}}};
string s;
vector<char> sol;
bool taken[9][9];
int deg[9][9], len, ans;

void uwu(int r, int c) {
    if(len < 48 && r == 7 && c == 1) return;
    if(len) {
        char t = sol.back();
        if(t == 'U' && taken[r - 1][c] && !taken[r][c - 1] && !taken[r][c + 1]) return;
        if(t == 'D' && taken[r + 1][c] && !taken[r][c - 1] && !taken[r][c + 1]) return;
        if(t == 'L' && taken[r][c - 1] && !taken[r - 1][c] && !taken[r + 1][c]) return;
        if(t == 'R' && taken[r][c + 1] && !taken[r + 1][c] && !taken[r - 1][c]) return;
    }
    taken[r][c] = true;
    deg[r - 1][c]--;
    deg[r + 1][c]--;
    deg[r][c + 1]--;
    deg[r][c - 1]--;
    len++;
    if(len == 49) ans++;
    else {
        char t = s[len - 1];
        if(t != '?') {
            auto p = dir[t];
            int rr = r + p.first, cc = c + p.second;
            if(!taken[rr][cc]) {
                sol.push_back(t);
                uwu(rr, cc);
                sol.pop_back();
            }
        }
        else {
            char forced = '*';
            if(!taken[r - 1][c] && deg[r - 1][c] == 1) forced = 'U';
            if(!taken[r + 1][c] && deg[r + 1][c] == 1) forced = 'D';
            if(!taken[r][c + 1] && deg[r][c + 1] == 1) forced = 'R';
            if(!taken[r][c - 1] && deg[r][c - 1] == 1) forced = 'L';
            if(forced != '*') {
                auto p = dir[forced];
                int rr = r + p.first, cc = c + p.second;
                if(!taken[rr][cc]) {
                    sol.push_back(forced);
                    uwu(rr, cc);
                    sol.pop_back();
                }
            }
            else {
                for(char k : "ULDR") {
                    auto p = dir[k];
                    int rr = r + p.first, cc = c + p.second;
                    if(!taken[rr][cc]) {
                        sol.push_back(k);
                        uwu(rr, cc);
                        sol.pop_back();
                    }
                }
            }
        }
    }

    deg[r - 1][c]++;
    deg[r + 1][c]++;
    deg[r][c + 1]++;
    deg[r][c - 1]++;
    len--;
    taken[r][c] = false;
}

int main() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            deg[i][j] = 4;
            if(i == 0 || i == 8 || j == 0 || j == 8) taken[i][j] = true;
        }
    }
    for(int i = 1; i < 8; i++) {
        deg[1][i]--;
        deg[7][i]--;
        deg[i][1]--;
        deg[i][7]--;
    }
    deg[7][1] = 1000;
    cin >> s;
    uwu(1, 1);
    cout << ans << '\n';
}