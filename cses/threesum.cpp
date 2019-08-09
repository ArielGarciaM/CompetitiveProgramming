#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<ii> v;
    int n, target;
    cin >> n >> target;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back({x, i + 1});
    }
    sort(v.begin(), v.end());
    for(int i = 2; i < n; i++) {
        int rem = target - v[i].first;
        int l = 0, r = i - 1;
        while(l < r) {
            if(v[l].first + v[r].first > rem) {
                r--;
                continue;
            }
            if(v[l].first + v[r].first == rem) {
                cout << v[l].second << " " << v[r].second << " " << v[i].second << '\n';
                return 0;
            }
            l++;
        }
    }
    cout << "IMPOSSIBLE\n";
}