#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
const int MAXN = 1e5 + 5;
set<int, greater<int>> ris[MAXN];
int ql[MAXN], qr[MAXN];

struct node {
    int mx, l, r;
    node *left, *right;

    node() {}
    node(int _l, int _r) : l(_l), r(_r) {
        if(l == r) 
            mx = -INF;
        else {
            int mi = (l + r)/2;
            left = new node(l, mi);
            right = new node(mi + 1, r);
            mx = max(left->mx, right->mx);
        } 
    }

    void upd(int p, int v) {
        if(r < p || p < l) return;
        if(l == r) { mx = v; return; }
        left->upd(p, v);
        right->upd(p, v);
        mx = max(left->mx, right->mx);
    }

    int qry(int rl, int rr) {
        if(r < rl || rr < l)
            return -INF;
        if(rl <= l && r <= rr)
            return mx;
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }
};
node iri, ilen;

bool check(int pos, int len) {
    if(len == 0) return true;
    int mil = max(0, pos - len + 1);
    if(ilen.qry(mil, pos) >= len) return true;
    if(pos - len < 0) return false;
    if(iri.qry(0, pos - len) >= pos) return true;
    return false;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, idx = 0;
    cin >> n;
    iri = node(0, n - 1);
    ilen = node(0, n - 1);

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r;
            cin >> l >> r;
            ris[l].insert(r);
            int R = *(ris[l].begin());
            iri.upd(l, R);
            ilen.upd(l, R - l + 1);
            //cout << l << " " << iri.qry(l, l) << " " << ilen.qry(l, l) << '\n';
            ql[idx] = l;
            qr[idx] = r;
            idx++;
        }
        if(t == 2) {
            int k;
            cin >> k;
            int l = ql[k], r = qr[k];
            ris[l].erase(r);
            if(ris[l].empty()) {
                iri.upd(l, -INF);
                ilen.upd(l, -INF);
            }
            else {
                int R = *(ris[l].begin());
                iri.upd(l, R);
                ilen.upd(l, R - l + 1);
                //cout << iri.qry(l, l) << " " << ilen.qry(l, l) << '\n';
            }
        }
        if(t == 0) {
            int pos;
            cin >> pos;
            int lo = 0, hi = n;
            while(lo < hi) {
                int mi = (lo + hi + 1)/2;
                if(check(pos, mi))
                    lo = mi;
                else
                    hi = mi - 1;
            }
            cout << lo << '\n';
        }
    }
}