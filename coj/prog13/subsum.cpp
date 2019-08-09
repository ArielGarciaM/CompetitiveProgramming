#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> pref;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    ll s;
    while(cin >> n >> s) {
        pref.clear();
        pref.push_back(0);
        for(int i = 1; i <= n; i++) {
            ll x;
            cin >> x;
            pref.push_back(pref.back() + x);
        }
        bool ansd = false;
        for(int i = 1; i <= n; i++) {
            if(binary_search(pref.begin(), pref.end(), pref[i] - s)) {
                ansd = true;
                for(int j = 0; j < i; j++) {
                    if(pref[j] == pref[i] - s) {
                        cout << j + 1 << " " << i << '\n';
                        break;
                    }
                }
            }
            if(ansd)
                break;
        }
        if(!ansd)
            cout << "-1\n";
    }
}