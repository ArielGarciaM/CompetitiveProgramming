#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
int f[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n == 1 || n % 2 == 0) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    if(n == 3) {
        cout << "1 2\n" << "2 3\n" << "3 4\n" << "4 5\n" << "5 6\n";
        return 0;
    }
    int p = 31 - __builtin_clz(n);
    for(int i = 1; i < (1 << p); i++) {
        f[i] = i;
        f[n + i] = n + i;
        if(i < (1 << p) - 1) {
            cout << i << " " << i + 1 << '\n';
            cout << n + i << " " << n + i + 1 << '\n';
        }
    }
    cout << (1 << p) - 1 << " " << n + 1 << '\n';
    for(int i = (1 << p); i < n; i += 2) {
        int x = i ^ (i + 1);
        int y = n + x;
        cout << i << " " << f[x] << '\n';
        cout << f[y] << " " << n + i + 1 << '\n';
        cout << i + 1 << " " << i << '\n';
        cout << n + i + 1 << " " << n + i << '\n';
        f[x] = i + 1;
        f[y] = n + i;
    }
}