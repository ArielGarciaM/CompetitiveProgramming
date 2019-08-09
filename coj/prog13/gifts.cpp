#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;
int n, BIT[MAXN], A[MAXN], pre[MAXN], ans[MAXN];
map<int, int> pv;

struct query {
    int l, k, idx;
};
vector<query> qs[MAXN];

void upd(int p, int v) {
    for(; p <= n; p += (p & -p)) BIT[p] += v;
}

int sum(int p) {
    int res = 0;
    for(; p > 0; p -= (p & -p)) res += BIT[p];
    return res;
}

int search(int sum) {
    int tot = 0, p = 0;
    for(int l = 20; l >= 0; l--) {
        if(p + (1 << l) <= n && tot + BIT[p + (1 << l)] < sum) {
            tot += BIT[p + (1 << l)];
            p += (1 << l);
        }
    }
    return p + 1;
}

void test_case() {
    pv.clear();
    for(int i = 1; i <= n; i++) {
        BIT[i] = 0;
        cin >> A[i];
        if(!pv.count(A[i]))
            pre[i] = 0;
        else
            pre[i] = pv[A[i]];
        pv[A[i]] = i;
    }
    //for(int i = 1; i <= n; i++)
    //    cout << pre[i] << " ";
    //cout << '\n';
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        qs[r].push_back({l, k, i});
    }
    for(int r = 1; r <= n; r++) {
        upd(r, 1);
        if(pre[r] > 0)
            upd(pre[r], -1);
        int ma = sum(r);
        for(auto q : qs[r]) {
            int bef = (q.l > 1 ? sum(q.l - 1) : 0);
            int req = bef + q.k;
            if(ma < req)
                ans[q.idx] = -1;
            else
                ans[q.idx] = A[search(bef + q.k)];
        }
        qs[r].clear();
    }
    for(int i = 0; i < q; i++) {
        if(ans[i] == -1)
            cout << ":(\n";
        else
            cout << ans[i] << '\n';
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    while(cin >> n)
        test_case();
}