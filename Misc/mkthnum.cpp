#include <bits/stdc++.h>
using namespace std;

struct node {
    node *left, *right;
    int l, r, val;
    
    node(int l, int r, int val = 0) : l(l), r(r), val(val), left(nullptr), right(nullptr) {}
    
    void merge() { val = left->val + right->val; }

    void build() {
        if(l == r)
            return;
        else {
            int mi = (l + r)/2;
            left = new node(l, mi);
            right = new node(mi + 1, r);
            left->build();
            right->build();
            merge();
        }
    }

    node* upd(int pos, int u) {
        if(pos < l || r < pos)
            return this;
        if(l == r)
            return new node(l, r, val + u);
        node* re = new node(l, r);
        re->left = left->upd(pos, u);
        re->right = right->upd(pos, u);
        re->merge();
        return re;
    }
};

int kth(node *lower, node *upper, int k) {
    if(lower->l == lower->r)
        return lower->l;
    int amt = upper->left->val - lower->left->val;
    if(amt >= k)
        return kth(lower->left, upper->left, k);
    else
        return kth(lower->right, upper->right, k - amt);
}

map<int, int> to, back;

int main() {
    int n, m;
    cin >> n >> m;
    vector<node*> trees(n + 1);
    trees[0] = new node(1, n);
    trees[0]->build();
    vector<int> a(n), sa;
    for(auto &x : a) cin >> x;
    sa = a;
    sort(sa.begin(), sa.end());
    int cur = 1;
    for(int i = 0; i < n; i++) {
        if(i > 0 && sa[i] != sa[i - 1]) cur++;
        to[sa[i]] = cur;
        back[cur] = sa[i];
    }
    for(int i = 0; i < n; i++)
        a[i] = to[a[i]];
    for(int i = 1; i <= n; i++)
        trees[i] = trees[i - 1]->upd(a[i - 1], 1);
    for(int i = 0; i < m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << back[kth(trees[l - 1], trees[r], k)] << endl;
    }
}

/*
7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3

*/