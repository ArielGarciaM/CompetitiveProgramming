#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> ct;
    vector<ii> v;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ct[x]++;
    }
    for(auto p : ct)
        v.push_back(p);
    if(v.size() >= 4 || (v.size() == 1 && v[0].first != 0)) {
        cout << "No\n";
        return 0;
    }
    int a, ca, b, cb, c, cc;
    a = v[0].first;
    ca = v[0].second;
    if(v.size() == 2) {
        if(a != 0 || v[1].second != 2*v[0].second) {
            cout << "No\n";
            return 0;
        }
    }
    if(v.size() == 3) {
        b = v[1].first;
        c = v[2].first;
        cb = v[1].second;
        cc = v[2].second;
        if(((a ^ b) != c) || ca != cb || ca != cc) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}