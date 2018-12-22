#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    set<ll> pts;
    pts.insert(0);
    ll sum = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum += x;
        if(i < n - 1)
            pts.insert(sum);
    }
    if(sum % 2)
    {
        cout << "N\n";
        return 0; 
    }
    int ans = 0;
    for(ll p : pts)
    {
        if(pts.count((p + sum / 2) % sum))
            ans++;
    }
    if(ans >= 4)
        cout << "Y\n";
    else
        cout << "N\n";
}