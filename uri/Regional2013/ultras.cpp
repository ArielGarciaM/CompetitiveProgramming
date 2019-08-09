#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int LG = 20;

int rminq[MAXN][LG], rmaxq[MAXN][LG];

int rq(int l, int r, int type) {
    int sz = 31 - __builtin_clz(r - l + 1);
    if(type == -1) {
        return min(rminq[l][sz], rminq[r - (1 << sz) + 1][sz]);
    }
    if(type == 1) {
        return max(rmaxq[l][sz], rmaxq[r - (1 << sz) + 1][sz]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            rminq[i][0] = rmaxq[i][0] = v[i];
        }
        for(int l = 1; l <= LG; l++) {
            for(int i = 0; i + (1 << l) - 1 < n; i++) {
                rminq[i][l] = min(rminq[i][l - 1], rminq[i + (1 << (l - 1))][l - 1]);
                rmaxq[i][l] = max(rmaxq[i][l - 1], rmaxq[i + (1 << (l - 1))][l - 1]);
            }
        }
        bool out = false;
        for(int i = 0; i < n; i++) {
            int top = v[i];
            int lo = i, hi = n - 1;
            //cout << rq(0, i, 1) << " " << rq(i, n - 1, 1) << endl;
            if(rq(i, n - 1, 1) > v[i]) {
                while(lo < hi) {
                    int mi = (lo + hi + 1)/2;
                    if(rq(i, mi, 1) <= v[i])
                        lo = mi;
                    else
                        hi = mi - 1;
                }
                //cout << lo << " " << rq(i + 1, lo, -1) << endl;
                top = min(top, v[i] - rq(i + 1, lo, -1));
            }
            lo = 0, hi = i;
            if(rq(0, i, 1) > v[i]) {
                while(lo < hi) {
                    int mi = (lo + hi)/2;
                    if(rq(mi, i, 1) <= v[i])
                        hi = mi;
                    else
                        lo = mi + 1;
                }
                top = min(top, v[i] - rq(lo, i - 1, -1));
            }
            //cout << top << endl;
            if(top >= 150000) {
                if(out)
                    cout << " ";
                else
                    out = true;
                cout << i + 1;
            }
        }
        cout << '\n';
    }
}