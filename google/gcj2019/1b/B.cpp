#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll R[7];

int main() {
    int t, w;
    cin >> t >> w;
    while(t--) {
        cout << "200\n";
        cout.flush();
        ll ans;
        cin >> ans;
        if(ans == -1)
            exit(0);
        R[4] = (ans)/(1ll << 50ll);
        ans %= (1ll << 50ll);
        R[5] = (ans)/(1ll << 40ll);
        ans %= (1ll << 40ll);
        R[6] = (ans)/(1ll << 33ll);

        cout << "50\n";
        cout.flush();
        cin >> ans;
        if(ans == -1)
            exit(0);

        ans -= R[4]*(1ll << 12);
        ans -= R[5]*(1ll << 10);
        ans -= R[6]*(1ll << 8);
        R[1] = (ans)/(1ll << 50ll);
        ans %= (1ll << 50ll);
        R[2] = (ans)/(1ll << 25ll);
        ans %= (1ll << 25ll);
        R[3] = (ans)/(1ll << 16ll);

        cout << R[1] << " " << R[2] << " " << R[3] << " " << R[4] << " " << R[5] << " " << R[6] << '\n';
        cout.flush();
        int r;
        cin >> r;
        if(r == -1)
            exit(0);
    }
}