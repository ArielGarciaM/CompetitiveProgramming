#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, i = 0, j = 0, ans = 0;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int it = 0; it < n; it++)
        cin >> a[it];
    for(int it = 0; it < m; it++)
        cin >> b[it];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while(i < n && j < m) {
        if(b[j] < a[i] - k)
            j++;
        else if(b[j] > a[i] + k)
            i++;
        else {
            ans++;
            i++;
            j++;
        }
    }
    cout << ans << endl;
}