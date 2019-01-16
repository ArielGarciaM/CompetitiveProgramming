#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r, lazy;
    vector<int> cnt;
    node *left, *right;

    int get(int i) {
        return cnt[(3 - lazy + i) % 3];
    }

    void merge() {
        for(int i = 0; i < 3; ++i)
            cnt[i] = left->get(i) + right->get(i);
    }

    node(int l, int r) : l(l), r(r){
        cnt = vector<int>(3);
        lazy = 0;
        if(l == r)
            cnt[0] = 1;
        else {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
            merge();
        }
    }

    void compose(int s) {
        lazy = (lazy + s)%3;
    }

    void push() {
        left->compose(lazy);
        right->compose(lazy);
        lazy = 0;
    }

    void upd(int rl, int rr) {
        if(r < rl || rr < l)
            return;
        if(rl <= l && r <= rr) {
            compose(1);
            return;
        }
        push();
        left->upd(rl, rr);
        right->upd(rl, rr);
        merge();
    }

    int qry(int rl, int rr) {
        if(r < rl || rr < l)
            return 0;
        if(rl <= l && r <= rr)
            return get(0);
        push();
        merge();
        return left->qry(rl, rr) + right->qry(rl, rr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    node tree = node(1, n);
    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l++, r++;
        if(t == 0)
            tree.upd(l, r);
        else
            cout << tree.qry(l, r) << '\n';
    }
}