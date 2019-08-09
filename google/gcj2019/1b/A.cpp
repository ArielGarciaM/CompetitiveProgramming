#include <bits/stdc++.h>
using namespace std;

const int MAXQ = 1e5 + 10;
int sweepU[MAXQ], sweepR[MAXQ];
int bx, by = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, P, Q;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        bx = by = 0;
        cin >> P >> Q;
        fill(sweepU, sweepU + MAXQ, 0);
        fill(sweepR, sweepR + MAXQ, 0);
        for(int i = 0; i < P; i++) {
            int x, y;
            char d;
            cin >> x >> y >> d;
            if(d == 'W' && x > 0) {
                sweepR[0]++;
                sweepR[x]--;
            }
            if(d == 'E')
                sweepR[x + 1]++;
            if(d == 'S' && y > 0) {
                sweepU[0]++;
                sweepU[y]--;
            }
            if(d == 'N')
                sweepU[y + 1]++;
        }
        int cur = 0, ax = 0, ay = 0;
        for(int i = 0; i <= Q + 1; i++) {
            cur += sweepR[i];
            if(cur > bx) {
                bx = cur;
                ax = i;
            }
        }
        cur = 0;
        for(int i = 0; i <= Q + 1; i++) {
            cur += sweepU[i];
            if(cur > by) {
                by = cur;
                ay = i;
            }
        }
        cout << "Case #" << tc << ": " << ax << " " << ay << '\n';
    }
}