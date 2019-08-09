#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

struct node {
    int l, r, sum;
    node *left, *right;

    node(int l, int r) : l(l), r(r) {}

    void build() {
        sum = 0;
        if(l != r) {
            int mi = (l + r)/2;
            left = new node(1, mi);
            right = new node(mi + 1, r);
            left->build();
            right->build();
        }
    }
};

node* upd(node* t, int pos, int val) {
    if(t->r < pos || pos < t->l)
        return t;
    node* res = new node(t->l, t->r);
    if(t->l == t->r)
        res->sum = t->sum + val;
    else {
        res->left = upd(t->left, pos, val);
        res->right = upd(t->right, pos, val);
        res->sum = res->left->sum + res->right->sum;
    }
    return res;
}

const int MAXN = 1e6 + 5, INF = 1e9 + 5;
int inv[MAXN], v[MAXN], sv[MAXN], l, r, k;
node* trees[MAXN];

int kth(node* t1, node* t2) {
    if(t1->l == t1->r)
        return t1->l;
    int inleft = t2->left->sum - t1->left->sum;
    if(inleft < k) {
        k -= inleft;
        return kth(t1->right, t2->right);
    }
    else
        return kth(t1->left, t2->left);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] += INF;
        sv[i] = v[i];
    }
    sort(sv, sv + n);
    gp_hash_table<int, int> comp;
    int pt = 1;
    comp[sv[0]] = pt, inv[pt] = sv[0];
    pt++;
    for(int i = 1; i < n; i++) {
        if(sv[i] != sv[i - 1]) {
            comp[sv[i]] = pt;
            inv[pt] = sv[i];
            pt++;
        }
    }
    for(int i = 0; i < n; i++)
        v[i] = comp[v[i]];
    trees[0] = new node(1, n);
    trees[0]->build();
    for(int i = 1; i <= n; i++)
        trees[i] = upd(trees[i - 1], v[i - 1], 1);
    while(q--) {
        cin >> l >> r >> k;
        cout << inv[kth(trees[l - 1], trees[r])] - INF << '\n';
    }
}