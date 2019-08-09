#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int pre[MAXN];
ll val[MAXN];

void test_case() {
    int n, q;
    cin >> n >> q;
    pre[0] = 0;
    val[0] = 1;
    int p = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x == 0)
            val[p]++;
        else {
            p++;
            pre[p] = pre[p - 1] + x;
            val[p] = 1;
        }
    }
    //for(int i = 0; i <= p; i++)
    //    cout << pre[i] << " " << val[i] << '\n';
    while(q--) {
        int k;
        cin >> k;
        ll ans = 0;
        int l = 0, r = 0;
        for(l = 0; l <= p; l++) {
            while(pre[r] < pre[l] + k && r <= p) r++;
            if(r > p) break;
            if(pre[r] == pre[l] + k) ans += val[l]*val[r];
        }
        cout << ans << " ";
    }
    cout << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        test_case();
}