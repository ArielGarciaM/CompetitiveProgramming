#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;

const double INF = 1e9;
vector<pdd> points;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    double ans = 0.0;
    pair<int, int> best;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back((double)x, (double)y);
    }
    double mx1, mn1, mx2, mn2;
    int mxv1, mnv1, mxv2, mnv2;
    for(int bm = 0; bm < 4; bm++) {
        mx1 = mx2 = -INF;
        mn1 = mn2 = INF;
        double sx = ((bm & 1) ? 1 : -1), sy = ((bm & 2) ? 1 : -1);
        for(int i = 1; i <= n; i++) {
            auto p = points[i - 1];
            if(sx*p.first + (sqrt(2) - 1)*sy*p.second > mx1)
                mx1 = sx*p.first + (sqrt(2) - 1)*sy*p.second, mxv1 = i;
            if(sx*p.second + (sqrt(2) - 1)*sy*p.first > mx2)
                mx2 = sx*p.second + (sqrt(2) - 1)*sy*p.first, mxv2 = i;
            if(sx*p.first + (sqrt(2) - 1)*sy*p.second < mn1)
                mn1 = sx*p.first + (sqrt(2) - 1)*sy*p.second, mnv1 = i;
            if(sx*p.second + (sqrt(2) - 1)*sy*p.first < mn2)
                mn2 = sx*p.second + (sqrt(2) - 1)*sy*p.first, mnv2 = i;
        }
        if(ans < mx1 - mn1) {
            ans = mx1 - mn1;
            best = {mxv1, mnv1};
        }
        if(ans < mx2 - mn2) {
            ans = mx2 - mn2;
            best = {mxv2, mnv2};
        }
    }
    cout << best.first << " " << best.second << endl;
}
