#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 3;

int main()
{
    long long n, ans = 0, a[MAXN];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long mult = n - 1;
    for(int i = n - 1; i >= 0; i--, mult -= 2)
    {
        ans += mult * a[i];
    }
    map<long long, long long> ct;
    for(int i = 0; i < n; i++)
    {
        int x = a[i];
        if(ct.count(x - 1))
            ans -= ct.count(x - 1);
        if(ct.count(x + 1))
            ans += ct.count(x + 1);
        ct[x]++;
    }
    cout << ans << endl;
}