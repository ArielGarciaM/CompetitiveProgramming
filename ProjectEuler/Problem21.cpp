#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    for(int a = 2; a < 10000; a++)
    {
        int b = 0;
        for(int d = 1; d < a; d++)
            if(a % d == 0) b += d;
        if(a == b)
            continue;
        int c = 0;
        for(int d = 1; d < b; d++)
            if(b % d == 0) c += d;
        if(a == c)
            ans += a;
    }
    cout << ans << endl;
}