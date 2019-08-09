#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;
const ll INF = 1e18;
ll d[MAXN], S[MAXN], f[MAXN], ub[MAXN], lb[MAXN], klb[MAXN];

struct node {
    int l, r;
    node *left, *right;
    ll mn, mx;

    inline void merge() { mx = max(left->mx, right->mx); mn = min(left->mn, right->mn); }
    node(int l, int r, ll *A) : l(l), r(r) {
        if(l == r) mn = mx = A[l];
        else {
            int m = (l + r)/2;
            left = new node(l, m, A);
            right = new node(m + 1, r, A);
            merge();
        }
    }
    ll qmin(int rl, int rr) {
        if(rr < l || r < rl) return INF;
        if(rl <= l && r <= rr) return mn;
        return min(left->qmin(rl, rr), right->qmin(rl, rr));
    }
    ll qmax(int rl, int rr) {
        if(rr < l || r < rl) return -INF;
        if(rl <= l && r <= rr) return mx;
        return max(left->qmax(rl, rr), right->qmax(rl, rr));
    }
};

bool cmp(const ll &a, const ll &b){ return a > b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    sort(d + 1, d + n + 1, cmp);
    // get S values
    S[0] = 0;
    for(int i = 1; i <= n; i++)
        S[i] = S[i - 1] + (ll)d[i];
    // get f values.
    for(int k = 1; k <= n; k++) {
        if(d[k] > k)
            f[k] = (ll)k*(ll)(n - k + 1);
        else {
            int lo = k, hi = n;
            while(lo < hi) {
                int mi = (lo + hi + 1)/2;
                if(d[mi] <= k) lo = mi;
                else hi = mi - 1;
            }
            f[k] = S[lo] - S[k - 1] + (ll)k*((ll)(n - lo));
        }
    }
    // calculate stuff
    for(ll k = 1; k <= n; k++) {
        ub[k] = k*(k + 1ll) + f[k + 1] - S[k];
        lb[k] = S[k] - f[k] + min((ll)d[k], k) - k*(k - 1ll);
        klb[k] = S[k] - f[k] + min((ll)d[k], k) - k*k;
    }
    // build trees
    node ubt(1, n, ub), lbt(1, n, lb), klbt(1, n, klb);
    ll cv = n, m = 1;
    if((cv % 2) != (S[n] % 2)) cv--;
    vector<ll> ans;
    for(; cv >= 0; cv -= 2) {
        if(cv > d[1]) {
            if(ubt.qmin(m, n) < cv)
                continue;
            ans.push_back(cv);
            continue;
        }
        if(cv <= d[n]) {
            if(klbt.qmax(1, n) > 0 || lbt.qmax(1, n) > cv || cv + S[n] > (ll)n*((ll)(n + 1)))
                continue;
            ans.push_back(cv);
            continue;
        }
        while(m < n + 1 && ((cv > d[m]) || (cv <= d[m + 1])))
            m++;
        //cout << cv << " " << m << " " << d[m - 1] << " " << d[m] << " " << d[m + 1] << endl;
        if(klbt.qmax(1, m) > 0 || lbt.qmax(1, m) > cv || ubt.qmin(m, n) < cv)
            continue;
        ans.push_back(cv);
    } 
    if(ans.empty()) {
        cout << "-1\n";
        return 0;
    }
    for(int i = ans.size() - 1; i >= 0; i--) {
        //if(i > 0) assert(ans[i] == ans[i - 1] - 2);
        //assert(ans[i] <= ((ll)n)*((ll)(n + 1ll)) - S[n]);
        cout << ans[i] << " ";
    }
    cout << endl;
}