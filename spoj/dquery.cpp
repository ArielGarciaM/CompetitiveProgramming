#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e4 + 5;
int k, cur, a[MAXN], D[1000010], ans[200010];

struct query {
    int l, r, idx;
    bool operator< (const query &o) const {
        if(l/k != o.l/k) return l/k < o.l/k;
        return r < o.r;
    }
};

void add(int p) { 
    if(!p) return;
    if(D[a[p]] == 0) cur++;
    D[a[p]]++;
}
void remove(int p) {
    if(!p) return;
    if(D[a[p]] == 1) cur--;
    D[a[p]]--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    k = sqrt(n);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    vector<query> qs(q);
    vector<int> ans(q);
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        qs[i] = {l, r, i};
    }
    int cl = 0, cr = 0;
    sort(qs.begin(), qs.end());
    for(int i = 0; i < q; i++) {
        int l = qs[i].l, r = qs[i].r;
        while(cr < r) ++cr, add(cr);
        while(cr > r) remove(cr), --cr;
        while(cl < l) remove(cl), ++cl;
        while(cl > l) --cl, add(cl);
        ans[qs[i].idx] = cur;
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}