#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const int MAXR = 1e3 + 5;
const int MAXD = 80;
ll brands[MAXR];
vector<int> ings[MAXD];
bool bad[MAXD][MAXD];

bool overflow(ll a, ll b) {
    // a * b > 10^18
    return a > INF/b;
}

int main() {
    int r, s, m, d, n;
    cin >> r >> s >> m >> d >> n;
    for(int i = 1; i <= r; i++)
        cin >> brands[i];
    for(int i = 1; i <= s + m + d; i++) {
        int k;
        cin >> k;
        while(k--) {
            int g;
            cin >> g;
            ings[i].push_back(g);
        }
    }
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        bad[x][y] = bad[y][x] = true;
    }
    ll ans = 0;
    for(int fs = 1; fs <= s; fs++) {
        for(int sn = s + 1; sn <= s + m; sn++) {
            for(int tr = s + m + 1; tr <= s + m + d; tr++) {
                if(bad[fs][sn] || bad[fs][tr] || bad[sn][tr])
                    continue;
                set<int> meal;
                for(auto i : ings[fs])
                    meal.insert(i);
                for(auto i : ings[sn])
                    meal.insert(i);
                for(auto i : ings[tr])
                    meal.insert(i);
                ll mult = 1;
                for(auto i : meal) {
                    ll b = brands[i];
                    if(overflow(mult, b)) {
                        cout << "too many\n";
                        return 0;
                    }
                    mult *= b;
                }
                ans += mult;
                if(ans > INF) {
                    cout << "too many\n";
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
}