#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n), lis(n), lds(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        for(int i = 0; i < n; i++) {
            lis[i] = 1;
            for(int j = i - 1; j >= 0; j--) {
                if(v[j] < v[i])
                    lis[i] = max(lis[i], 1 + lis[j]);
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            lds[i] = 1;
            for(int j = i + 1; j < n; j++) {
                if(v[i] > v[j])
                    lds[i] = max(lds[i], 1 + lds[j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, lis[i] + lds[i] - 1);
        cout << ans << '\n';
    }
}