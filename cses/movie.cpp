#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t = 0, ans = 0;
    cin >> n;
    vector<ii> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end());
    for(auto p : v) {
        if(p.second >= t) {
            t = p.first;
            ans++;
        }
    }
    cout << ans << '\n';
}