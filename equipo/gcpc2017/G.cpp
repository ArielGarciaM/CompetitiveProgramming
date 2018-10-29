#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> x;
    vector<long long> y;
    for(int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    long long a = 0, b = 0;
    for(int i = 0; i < n; i++)
    {
        long long x1 = x[i], y1 = y[i], x2 = x[(i + 1)%n], y2 = y[(i + 1)%n];
        a += (x1 * y2) - (x2 * y1);
        b += __gcd(abs(x1 - x2), abs(y1 - y2));
    }
    cout << (abs(a) - b + 2ll)/2ll << endl;
}