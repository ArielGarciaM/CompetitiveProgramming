#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, target;
    cin >> n >> target;
    vector<ii> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    while(l < r) {
        while(r >= 0 && v[l].first + v[r].first > target)
            r--;
        if(l != r && v[l].first + v[r].first == target) {
            cout << v[l].second + 1 << " " << v[r].second + 1 << '\n';
            return 0;
        }
        l++;
    }
    cout << "IMPOSSIBLE\n";
}