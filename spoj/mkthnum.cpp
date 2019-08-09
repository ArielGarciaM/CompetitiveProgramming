#include <bits/stdc++.h>
using namespace std;

struct nodo {
    vector<int> cleft;
    nodo *left, *right;
    int lo, hi;

    nodo(int l, int r, int *pointl, int *pointr) {
        lo = l;
        hi = r;
        if(l == r || pointl == pointr)
            return;

        int mi = (lo + hi)/2;
        auto f = [mi](int x) {
            return x <= mi;
        };
        cleft.push_back(0);
        for(auto it = pointl; it != pointr; it++) {
            cleft.push_back(cleft.back() + f(*it));
        }

        auto fin = stable_partition(pointl, pointr, f);
        left = new nodo(l, mi, pointl, fin);
        right = new nodo(mi + 1, r, fin, pointr);
    }

    int kth(int L, int R, int k) {
        if(lo == hi)
            return lo;
        int inleft = cleft[R] - cleft[L - 1];
        int der = cleft[R];
        int izq = cleft[L - 1];
        if(inleft >= k)
            return left->kth(izq + 1, der, k);
        else
            return right->kth(L - izq, R - der, k - inleft);
    }
};

const int MAXN = 1e5 + 5;
int A[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    nodo wavelet(-1e9, 1e9, A, A + n);
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << wavelet.kth(l, r, k) << endl;
    }
}