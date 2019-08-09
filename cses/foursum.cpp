#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    map<int, ii> seensums;
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int rem = target - v[i] - v[j];
            if(seensums.count(rem)) {
                cout << i + 1 << " " << j + 1 << " " << seensums[rem].first << " " << seensums[rem].second << '\n';
                return 0;
            }
        }
        for(int j = 0; j < i; j++)
            seensums[v[i] + v[j]] = {i + 1, j + 1};
    }
    cout << "IMPOSSIBLE\n";
}