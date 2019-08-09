#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int BIT[MAXN], a[MAXN];

void upd(int p, int v) {
    for(;p < MAXN; p += (p & -p))
        BIT[p] += v;
}

int qry(int p) {
    int s = 0;
    for(;p > 0; p -= (p & -p))
        s += BIT[p];
    return s;
}

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = n - 1;
    for(int i = n - 1; i >= 1; i--) {
        if(a[i] < a[i + 1])
            ans--;
        else
            break;
    }
    int mn = ans - 1;
    memset(BIT, 0, sizeof(BIT));
    for(int i = ans + 1; i <= n; i++)
        upd(a[i], 1);
    cout << ans << endl;
    for(int i = 1; i <= ans; i++) {
        cout << mn + qry(a[i] - 1);
        if(i < ans)
            cout << " ";
        upd(a[i], 1);
        mn--;
    }
    cout << endl;
}