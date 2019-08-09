#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;
ll a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    if(n == 1) {
        cout << "0\n";
        return 0;
    }
    vector<ll> v(n - 1);
    v[0] = a[0] - b[0];
    for(int i = 1; i < n - 1; i++)
        v[i] = a[i] - b[i] + v[i - 1];
    sort(v.begin(), v.end());
    ll k = v.size();
    ll lt = 0, gt = accumulate(v.begin(), v.end(), 0ll);
    ll ans = 0;
    for(auto x : v)
        ans += abs(x);
    gt -= v[0];
    ans = min(ans, gt - v[0]*(k - 1) + abs(v[0]));
    for(int i = 1; i < k; i++) {
        lt += v[i - 1];
        gt -= v[i];
        ans = min(ans, abs(v[i]) + gt - lt + v[i]*(i - (k - i - 1)));
    }
    cout << ans << endl;
}