#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

struct node {
    int l, r, lazy, n, spec;
    node *left, *right;
    vi mx;

    inline int getmx(int m) { return spec ? mx[m^lazy] : -1; }
    inline void merge() {
        for(int m = 0; m < (1 << n); m++)
            mx[m] = max(left->getmx(m), right->getmx(m));
        spec = left->spec + right->spec;
    }
    inline void compose(int m) { lazy ^= m; }
    inline void push() {
        left->compose(lazy);
        right->compose(lazy);
        lazy = 0;
        merge();
    }

    node(int l, int r, int n, int *A, bool *B) : l(l), r(r), n(n), lazy(0) {
        mx.resize((1 << n));
        if(l == r) {
            for(int m = 0; m < (1 << n); m++)
                mx[m] = __builtin_popcount(A[l] ^ m);
            spec = B[l] ? 1 : 0;
        }
        else {
            int mi = (l + r)/2;
            left = new node(l, mi, n, A, B);
            right = new node(mi + 1, r, n, A, B);
            merge();
        }
    }

    void upd(int rl, int rr, int msk) {
        if(r < rl || rr < l || rl > rr || !spec) return;
        if(rl <= l && r <= rr) {
            compose(msk);
            return;
        }
        push();
        left->upd(rl, rr, msk);
        right->upd(rl, rr, msk);
        merge();
    }

    int qry(int rl, int rr) {
        if(r < rl || rr < l || rl > rr || rr < 0 || !spec) return -1;
        if(rl <= l && r <= rr) return getmx(0);
        push();
        merge();
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }

    void out() {
        if(!this) return;
        cout << l << " " << r << " " << lazy << " " << getmx(0) << endl;
        left->out();
        right->out();
    }
};

vi zfunc(string &s) {
    int n = s.length();
    vi z(n);
    int L = -1, R = -1;
    for(int i = 1; i < n; i++) {
        if(i <= R) z[i] = min(z[i - L], R - i + 1);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1;
    }
    return z;
}

const int MAXN = 1e5 + 5;
int C[MAXN], X[MAXN];
bool Y[MAXN];
string s;

int main() {
    int q;
    while(cin >> q) {
        string t;
        cin >> t;
        int n = t.length(), msk = 0;
        for(int i = 0; i < n; i++) {
            if('A' <= t[n - 1 - i] && t[n - 1 - i] <= 'Z')
                msk |= (1 << i);
        }
        //cout << "mask: " << msk << endl;
        for(auto &c : t)
            c = tolower(c);
        string s;
        cin >> s;
        int m = s.length();
        fill(X, X + m, 0);
        fill(Y, Y + m, false);
        for(int i = 0; i < m; i++) {
            if('A' <= s[i] && s[i] <= 'Z') C[i] = 1;
            else C[i] = 0;
            s[i] = tolower(s[i]);
        }
        string zs = t + '#' + s;
        auto z = zfunc(zs);
        for(int i = 0; i + n - 1 < m; i++) {
            int x = 0;
            for(int j = 0; j < n; j++) {
                x *= 2;
                x += C[i + j];
            }
            x ^= msk;
            X[i] = x;
            //cout << "pos " << i << ": " << X[i] << endl;
        }
        for(int i = n + 1; i <= n + m; i++) {
            if(z[i] == n) {
                //cout << i - n - 1 << endl;
                Y[i - n - 1] = true;
            }
        }
        node tree(0, m - 1, n, X, Y);
        for(int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            cout << tree.qry(l, r - n + 1) << endl;
            for(int b = 0; b < n; b++)
                tree.upd(l - n + b + 1, r - n + b + 1, (1 << b));
        }
    }
    /*string s;
    cin >> s;
    Y[0] = true;
    Y[3] = true;
    Y[8] = true;
    for(int i = 0; i < s.length(); i++)
        X[i] = (16*(s[i] - '0') + 8*(s[i + 1] - '0') + 4*(s[i + 2] - '0') + 2*(s[i + 3] - '0') + (s[i + 4] - '0'))^6;
    node tree(0, s.length() - 1, 5, X, Y);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        cout << tree.qry(l, r - 4) << endl;
        tree.upd(l - 4, r, 1);
        tree.upd(l - 3, r + 1, 2);
        tree.upd(l - 2, r + 2, 4);
        tree.upd(l - 1, r + 3, 8);
        tree.upd(l, r + 4, 16);
        //tree.out();
    }*/
}