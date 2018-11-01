#include <bits/stdc++.h>
using namespace std;

long long bound = 1e16;
vector<long long> powt;
vector<long long> x;

int main()
{
    int t;
    cin >> t;
    powt.push_back(2ll);
    x.push_back(1ll);
    for(long long i = 0; i < 62; i++)
    {
        powt.push_back(powt[i]*2ll);
        x.push_back((i + 2ll)*powt[i]);
        if(2*powt[i + 1] > bound)
            break;
    }
    while(t--)
    {
        long long n;
        cin >> n;
        long long ans = 0;
        for(long long i = 0; i < powt.size(); i++)
        {
            ans = ans + (n / powt[i])*x[i];
        }
        cout << ans << endl;
    }
}