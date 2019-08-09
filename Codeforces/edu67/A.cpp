#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, s, t;
        cin >> n >> s >> t;
        int dou = s + t - n;
        s -= dou;
        t -= dou;
        cout << max(s, t) + 1 << '\n';
    }
}