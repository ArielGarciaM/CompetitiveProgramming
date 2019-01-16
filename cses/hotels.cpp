#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;

struct node {
    int l, r, val;
    node *left, *right;
    node(int l, int r, vector<int> &A) : l(l), r(r) {
        if(l == r)
            val = A[l];
        else {
            int m = (l + r)/2;
            left = new node(l, m, A);
            right = new node(m + 1, r, A);
            val = max(left->val, right->val);
        }
    }

    void update(int pos, int upd) {
        if(pos < l || r < pos)
            return;
        if(l == r) {
            val = upd;
            return;
        }
        left->update(pos, upd);
        right->update(pos, upd);
        val = max(left->val, right->val);
    }

    int query(int rl, int rr) {
        if(r < rl || rr < l)
            return -INF;
        if(rl <= l && r <= rr)
            return val;
        return max(left->query(rl, rr), right->query(rl, rr));
    }
};

int bs(int bnd, node &tree) {
    int lo = 1, hi = n;
    if(tree.query(1, n) < bnd)
        return 0;
    while(lo != hi) {
        int mi = (lo + hi)/2;
        if(tree.query(1, mi) < bnd)
            lo = mi + 1;
        else
            hi = mi;
    }
    return lo;
}

int main() {
    int m;
    cin >> n >> m;
    vector<int> hotels(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> hotels[i];
    node tree = node(1, n, hotels);
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int pos = bs(x, tree);
        cout << pos << " ";
        if(pos != 0) {
            hotels[pos] -= x;
            tree.update(pos, hotels[pos]);
        }
    }
    cout << endl;
}