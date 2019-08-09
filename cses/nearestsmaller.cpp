#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n), nearest(n);
    vector<ii> sta;
    for(auto &x : v)
        cin >> x;
    for(int i = 0; i < n; i++) {
        while(!sta.empty() && v[i] <= sta.back().first)
            sta.pop_back();
        if(sta.empty())
            nearest[i] = 0;
        else
            nearest[i] = sta.back().second;
        sta.push_back({v[i], i + 1});
    }
    for(int i = 0; i < n; i++)
        cout << nearest[i] << " ";
    cout << '\n';
}