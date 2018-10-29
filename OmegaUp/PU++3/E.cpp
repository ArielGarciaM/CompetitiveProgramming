#include <bits/stdc++.h>
using namespace std;

double m, g, v, eps = 1e9;

double dist(double x)
{
    return x*sqrt(v*v - x*x) - m*x*x;
}

double ts()
{
    double low = 0, high = v;
    for(int i = 0; i < 300; i++)
    {
        double diff = (high - low)/3.0;
        double f1 = dist(low + diff), f2 = dist(high - diff);
        if(f1 < f2)
            low += diff;
        else
            high -= diff;
    }
    return low;
}

int main()
{
    cin >> m >> g >> v;
    double vx = ts(), vy = sqrt(v*v - vx*vx);
    cout << fixed << setprecision(10) << atan(vy/vx) << endl;
}