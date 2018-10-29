#include <bits/stdc++.h>
using namespace std;

int coll(long long n)
{
    int tot = 0;
    while(n > 1)
    {
        tot++;
        if(n % 2)
            n = 3*n + 1;
        else
            n /= 2;
    }
    return tot;
}

int main()
{
    int mx = 0, ans = 0;
    for(long long i = 1; i < 1000000; i++)
    {
        int c = coll(i);
        if(c > mx)
        {
            mx = c;
            ans = i;
        }
    }
    cout << mx << " " << ans << endl;
}