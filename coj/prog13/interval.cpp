#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXL = 1e5 + 5;
int BIT[MAXL], cnt[MAXL];

void upd(int p, int v) {
    for(; p < MAXL; p += (p & -p)) BIT[p] += v;
}

int sum(int p) {
    int res = 0;
    for(; p > 0; p -= (p & -p)) res += BIT[p];
    return res;
}

int bound(int target) { // return largest x s.t. sum[1..x] < target
    int pos = 0, sum = 0;
    for(int l = 20; l >= 0; l--) {
        if(pos + (1 << l) < MAXL && sum + BIT[pos + (1 << l)] < target) {
            sum += BIT[pos + (1 << l)];
            pos += (1 << l);
        }
    }
    return pos;
}

void test_case() {
    int n;
    cin >> n;

    memset(BIT, 0, sizeof BIT);
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        upd(x, 1);
    }
    int q;
    cin >> q;
    while(q--) {
        int t, y;
        cin >> t >> y;
        if(t == 2) {
            upd(y, 1);
            cnt[y]++;
        }
        if(t == 3) {
            if(!cnt[y]) continue;
            upd(y, -1);
            cnt[y]--;
        }
        if(t == 1) {
            int x = -1, z = 100001;
            if(y > 1) {
                int bnd = sum(y - 1);
                if(bnd > 0)
                    x = bound(bnd) + 1;
            }
            if(y < 100000) {
                int bnd = sum(y);
                int k = bound(bnd + 1);
                if(k + 1 < z)
                    z = k + 1;
            }
            cout << x << " " << z << '\n';
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        test_case();    
}