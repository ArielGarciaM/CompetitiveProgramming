#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, cur = 0, ans = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x: v)
        cin >> x;
    ans = accumulate(v.begin(), v.end(), 0);
    priority_queue<int> active;
    for(int i = n - 1; i >= 0; i--) {
        active.push(v[i]);
        if(i % (k + 1) == k) {
            ans -= active.top();
            active.pop();
        }
    }
    cout << ans << endl;
}