#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

multiset<ii> rooks;
int col[1000], row[1000];
ii pos[667], cur;

void query(int rx, int ry) {
    cout << rx << " " << ry << endl;
    cout << flush;
    int k, x, y;
    cin >> k >> x >> y;
    if(k <= 0)
        exit(0);
    ii pre = pos[k];
    row[pre.first]--;
    col[pre.second]--;
    row[x]++;
    col[y]++;
    rooks.erase(rooks.find(pre));
    rooks.insert({x, y});
    pos[k] = {x, y};
}

vector<ii> dir = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

int main() {
    int sx, sy;
    cin >> sx >> sy;
    cur = {sx, sy};
    for(int i = 1; i <= 666; i++) {
        int x, y;
        cin >> x >> y;
        pos[i] = {x, y};
        rooks.insert({x, y});
        row[x]++;
        col[y]++;
    }
    while(true) {
        int mr = 0, mc = 0;
        for(int i = 1; i <= 999; i++) {
            if(row[i] > mr)
                mr = i;
        }
        for(int j = 1; j <= 999; j++) {
            if(col[j] > mc)
                mc = j;
        }
        ii dst = {mr, mc};
        int mdis = 10000000;
        ii move = {cur.first + (rand() % 3 - 1), cur.second + (rand() % 3 - 1)};
        for(auto p : dir) {
            int nx = cur.first + p.first, ny = cur.second + p.second;
            if(nx <= 0 || nx > 999 || ny <= 0 || ny > 999)
                continue;
            bool b = true;
            for(int i = 1; i <= 666; i++) {
                if(pos[i] == ii{nx, ny});
                b = false;
            }
            if(!b)
                continue;
            if(row[nx] > 0 || col[ny] > 0)
                query(nx, ny);
            if(abs(nx - mr) + abs(ny - mc) < mdis) {
                mdis = abs(nx - mr) + abs(ny - mc);
                move = {nx, ny};
            }
        }
        if(move.first > 0 && move.first < 1000 && move.second > 0 && move.second < 1000 && (move.first != cur.first || move.second != cur.second)) {
            cur = {move.first, move.second};
            query(move.first, move.second);
        }
    }
}