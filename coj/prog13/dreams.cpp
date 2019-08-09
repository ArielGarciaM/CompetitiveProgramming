#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1005;
int good[MAXN];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        memset(good, 0, sizeof good);
        while(m--) {
            int x;
            cin >> x;
            good[x] = 1;
        }
        for(int i = 1; i <= n; i++)
            if(!good[i]) cout << i << " ";
        cout << '\n';
    }    
}