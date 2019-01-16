#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int A[MAXN];

struct segtree {
    int l, r, val;
    segtree *left, *right;

    segtree(int l, int r) : l(l), r(r) {
        if(l == r)
            val = A[l];
        else {
            int m = (l + r)/2;
            left = new segtree(l, m);
            right = new segtree(m+1 , r);
            val = left->val * right->val;
        }
    }

    void update(int pos, int val) {
        if(r < pos || pos < l)
            return;
        if(l == r)
            this->val = val;
        else {
            left->update(pos, val);
            right->update(pos, val);
            this->val = left->val * right->val;
        }
    }

    int query(int rl, int rr) {
        if(r < rl || rr < l)
            return 1;
        if(rl <= l && r <= rr)
            return val;
        return left->query(rl, rr) * right->query(rl, rr);
    }
};

int main() {
    int n, q;
    while(cin >> n >> q)
    {
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if(x > 0)
                A[i] = 1;
            if(x < 0)
                A[i] = -1;
            if(x == 0)
                A[i] = 0;
        }
        segtree st = segtree(1, n);
        for(int i = 0; i < q; i++) {
            char t;
            cin >> t;
            if(t == 'C') {
                int p, c;
                cin >> p >> c;
                if(c > 0)
                    c = 1;
                if(c < 0)
                    c = -1;
                st.update(p, c);
            }
            else {
                int l, r;
                cin >> l >> r;
                int a = st.query(l, r);
                if(a == 1)
                    cout << '+';
                if(a == -1)
                    cout << '-';
                if(a == 0)
                    cout << '0';
            }
        }
        cout << endl;
    }
}