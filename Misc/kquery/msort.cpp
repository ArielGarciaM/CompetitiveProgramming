#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct node {
    int l, r;
    vi v;
    node *left, *right;

    node(int l, int r, int* A) : l(l), r(r) {
        if(l == r)
            v = {A[l]};
        else {
            int mi = (l + r)/2;
            left = new node(l, mi, A);
            right = new node(mi + 1, r, A);
            merge(left->v.begin(), left->v.end(), right->v.begin(), right->v.end(), back_inserter(v));
        }
    }

    int quantile(int rl, int rr, int k) {
        if(rr < l || r < rl || rl > rr)
            return 0;
        if(rl <= l && r <= rr) {
            int d = r - l;
            if(v[d] <= k) return 0;
            int lo = 0, hi = d;
            while(lo < hi) {
                int mi = (lo + hi)/2;
                if(v[mi] > k) hi = mi;
                else lo = mi + 1;
            }
            return d + 1 - lo;
        }
        return left->quantile(rl, rr, k) + right->quantile(rl, rr, k);
    }
};

const int MAXN = 3e4 + 5;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, last = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    node tree(1, n, a);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l ^= last;
        r ^= last;
        k ^= last;
        if(l < 1) l = 1;
        if(r > n) r = n;
        // cout << "decoded: " << l << " " << r << " " << k << endl;
        last = tree.quantile(l, r, k);
        cout << last << '\n';
    }
}