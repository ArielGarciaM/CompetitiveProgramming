#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, w;
    cin >> n >> l >> w;
    vector<int> pts(n);
    for(int i = 0; i < n; i++)
        cin >> pts[i];
    sort(pts.begin(), pts.end());
    double ans = 0;
    for(int i = 0; i < n; i += 2)
    {
        if(i == n - 2)
        {
            ans += min(hypot(l - pts[i], w) + fabs(l - pts[i + 1]), hypot(l - pts[i + 1], w) + fabs(l - pts[i]));
            continue;
        }
        ans += hypot(pts[i + 1] - pts[i], w);
    }
    cout << fixed << setprecision(20);
    cout << ans << endl;
}