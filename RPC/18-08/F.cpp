#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll w, sum = 0;
    int n;
    cin >> w >> n;
    while(n--)
    {
        ll x, y;
        cin >> x >> y;
        sum += x*y;
    }
    cout << sum/w << endl;
}