#include <bits/stdc++.h>
using namespace std;

const int P0 = 1, P1 = 101, P2 = 101*101, P3 = 101*101*101;

int rep(int a, int b, int c, int d) {
    int w = a*P0 + b*P1 + c*P2 + d*P3;
    int x = b*P0 + c*P1 + d*P2 + a*P3;
    int y = c*P0 + d*P1 + a*P2 + b*P3;
    int z = d*P0 + a*P1 + b*P2 + c*P3;
    return min({w, x, y, z});
}

map<int, vector<int>> mp;

int A[505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    while(cin >> n >> k, n > 0) {
        mp.clear();
        while(k--) {
            int a, b, c, d, v;
            cin >> a >> b >> c >> d >> v;
            mp[rep(a, b, d, c)].push_back(v);
        }
        for(auto& p : mp)
            sort(p.second.begin(), p.second.end());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> A[i][j];

        int ans = 0;
        bool bad = false;
        for(int i = 0; i < n; i += 2) {
            for(int j = 0; j < n; j += 2) {
                int r = rep(A[i][j], A[i][j + 1], A[i + 1][j + 1], A[i + 1][j]);
                if(mp[r].empty()) {
                    bad = true;
                    break;
                }
                else {
                    ans += mp[r].back();
                    mp[r].pop_back();
                }
            }
            if(bad)
                break;
        }
        cout << (bad ? -1 : ans) << '\n';
    }
}