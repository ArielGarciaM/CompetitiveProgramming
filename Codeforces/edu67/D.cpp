#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 3e5 + 5;
int BIT[MAXN];

void upd(int p, int v) {
    for(;p < MAXN;p += (p & -p)) BIT[p] += v;
}

int sum(int p) {
    int res = 0;
    for(; p > 0; p -= (p & -p)) res += BIT[p];
    return res;
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n + 2; i++)
        BIT[i] = 0;
    set<ii, greater<ii>> sa, sb;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sa.insert({x, sum(x)});
        upd(x, 1);
    }
    for(int i = 0; i < n + 2; i++)
        BIT[i] = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sb.insert({x, sum(x)});
        upd(x, 1);
    }
    for(int i = 0; i < n; i++) {
        auto p1 = *sa.begin(), p2 = *sb.begin();
        if(p1.first != p2.first) {
            cout << "NO\n";
            return;
        }
        if(p1.second > p2.second) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}