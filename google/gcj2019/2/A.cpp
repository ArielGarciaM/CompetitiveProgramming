#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        vector<ii> pts(n);
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            pts[i] = {x, y};
        }
        set<ii> slopes;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                ii p1 = pts[i], p2 = pts[j];
                if(p1.first == p2.first)
                    continue;
                if(p1.first > p2.first)
                    swap(p1, p2);
                if(p2.second >= p1.second)
                    continue;
                int dx = p2.first - p1.first, dy = p1.second - p2.second;
                dx = abs(dx);
                dy = abs(dy);
                int g = __gcd(dx, dy);
                slopes.insert({dx/g, dy/g});
            }
        }
        cout << "Case #" << tc << ": " << slopes.size() + 1 << endl;
    }
}