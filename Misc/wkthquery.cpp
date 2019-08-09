#include <bits/stdc++.h>
using namespace std;

struct wnode {
    wnode *left, *right;
    int lo, hi;
    vector<int> c;
    wnode(int lo, int hi, int* st, int* en) : lo(lo), hi(hi) {
        if(hi == lo || st == en)
            return;
        int mi = (lo + hi)/2;
        auto f = [mi](int x) {return x <= mi;};
        c.push_back(0);
        for(auto it = st; it != en; ++it)
            c.push_back(c.back() + f(*it));
        auto it = stable_partition(st, en, f);
        left = new wnode(lo, mi, st, it);
        right = new wnode(mi + 1, hi, it, en);
    }
    int leq(int L, int R, int k) {
        //cout << L << " " << R << " " << lo << " " << hi << endl;
        if(L > R)
            return 0;
        if(hi <= k)
            return R - L + 1;
        if(lo > k)
            return 0;
        int der = c[R], izq = c[L - 1], tol = der - izq;
        return left->leq(izq + 1, der, k) + right->leq(L - izq, R - der, k);
    }
};

int a[300005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    wnode wtree(1, 1000000000, a, a + n);
    int last = 0;
    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        a ^= last;
        b ^= last;
        c ^= last;
        if(a < 1)
            a = 1;
        if(b > n)
            b = n;
        //cout << "decoded " << a << " " << b << " " << c << endl;
        int r = wtree.leq(a, b, c);
        last = (b - a + 1) - r;
        cout << last << '\n';
    }
}