#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct wnode {
    int lo, hi;
    vi cleft;
    wnode *left, *right;

    wnode(int lo, int hi, int *st, int *en) : lo(lo), hi(hi), left(nullptr), right(nullptr) {
        if(lo == hi || st == en) return;
        int mi = (lo + hi)/2;
        auto f = [mi](int x){ return x <= mi; };
        cleft.push_back(0);
        for(auto it = st; it != en; ++it) cleft.push_back(cleft.back() + f(*it));
        auto it = stable_partition(st, en, f);
        left = new wnode(lo, mi, st, it);
        right = new wnode(mi + 1, hi, it, en);
    }

    int quantile(int l, int r, int k) {
        if(l > r || hi <= k) return 0;
        if(lo > k) return r - l + 1;
        int izq = cleft[l - 1], der = cleft[r];
        return left->quantile(izq + 1, der, k) + right->quantile(l - izq, r - der, k);
    }
};

const int MAXN = 3e4 + 5;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    wnode tree(1, 1e9, a, a + n);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << tree.quantile(l, r, k) << '\n';
    }
}