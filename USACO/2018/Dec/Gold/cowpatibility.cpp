#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;
vector<vector<int>> v;

int main(){
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        v.push_back({});
        for(int j = 0; j < 5; j++) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            set<int> s;
            for(auto x : v[i])
                s.insert(x);
            for(auto x : v[j])
                s.insert(x);
            if(s.size() == 10)
                ans++;
        }
    }
    cout << ans << endl;
}