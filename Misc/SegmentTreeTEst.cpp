#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r, val;
    node(int l = 0, int r = 0, int val = 0) : l(l), r(r), val(val){}
};

struct SegmentTree {
    int n;
    vector<node> tree;
    vector<int> pos;

    SegmentTree(int n, vector<int> &A) {
        tree.clear();
        pos.clear();
        tree.resize(4*n);
        pos.resize(4*n);
        build(1, n, A);
    }

    void build(int l, int r, vector<int> &A, int id = 1) {
        tree[id] = node(l, r);
        if(l == r) {
            tree[id].val = A[l];
            pos[l] = id;
        }
        else {
            int m = (l + r)/2;
            build(l, m, A, 2*id);
            build(m + 1, r, A, 2*id + 1);
            tree[id].val = tree[2*id].val + tree[2*id + 1].val;
        }
    }

    void update(int lf, int val) {
        int id = pos[lf];
        tree[id].val = val;
        while(id > 0) {
            id /= 2;
            tree[id].val = tree[2*id].val + tree[2*id + 1].val;
        }
    }

    int query(int l, int r, int id = 1) {
        node n = tree[id];
        if(n.r < l || n.l > r)
            return 0;
        if(l <= n.l || n.r <= r)
            return n.val;
        return query(l, r, 2*id) + query(l, r, 2*id + 1);
    }
};

int main() {
    double worstratio = 0;
    for(int num = 1; num <= 20000; num++) {
        int n = num, cnt = 0, mx = 0;
        //cin >> n;
        vector<int> A(n + 1);
        for(int i = 1; i <= n; i++)
            A[i] = rand() % 200;
        SegmentTree st = SegmentTree(n, A);
        for(int i = 1; i < 4*n; i++) {
            node n = st.tree[i];
            if(n.l != 0) {
                cnt++;
                mx = max(i, mx);
                //cout << "Node " << i << ": (" << n.l << ", " << n.r << ") value " << n.val << endl;
            }
        }
        //cout << cnt << " nodes. (" << (double)mx/(double)n << " ratio)" << endl;
        double ratio = (double)mx/(double)n;
        if(ratio > worstratio) {
            cout << "Oops, new worst ratio is " << ratio << " with n = " << n << endl;
            worstratio = ratio;
        }
    }
    cout << worstratio << endl;
}