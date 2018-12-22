#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-9;
const long double PI = 3.141592653589793;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n;
    vector<long double> xs, ys, ang;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long double x, y;
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
    }
    for(int i = 0; i < n; i++)
    {
        long double x1 = xs[i], y1 = ys[i], x2 = xs[(i + 1)%n], y2 = ys[(i + 1)%n];
        ang.push_back(atan2(y2 - y1, x2 - x1));
    }
    for(int i = 0; i < n; i++)
    {
        if(ang[i] < 0)
            ang[i] += 2.0*PI;
    }
    sort(ang.begin(), ang.end());
    long long bad = 0, k;
    for(int i = 0; i < n; i++)
    {
        long double a = ang[i];
        if(a < PI - eps)
        {
            auto it = lower_bound(ang.begin(), ang.end(), a + PI + eps);
            k = distance(ang.begin(), it) - i - 1;
            bad += k*(k - 1)/2;
        }
        else
        {
            auto it = lower_bound(ang.begin(), ang.end(), a - PI + eps);
            k = (n - i - 1) + distance(ang.begin(), it);
            bad += k*(k - 1)/2;
        }
    }
    long long ans = n*(n - 1)*(n - 2)/6 - bad;
    cout << ans << endl;
}