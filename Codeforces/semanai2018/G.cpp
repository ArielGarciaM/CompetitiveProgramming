#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {   
        ll a, b, c, d, e, f;
        scanf("%lld/%lld %lld/%lld %lld/%lld", &a, &b, &c, &d, &e, &f);
        ll num, dem;
        dem = b*d*f;
        num = a*d*f + c*b*f + e*b*d;
        ll g = __gcd(num, dem);
        num /= g;
        dem /= g;
        cout << num << "/" << dem << endl;
    }
}