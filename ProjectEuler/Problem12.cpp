#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(long long n = 1;;n++)
    {
        long long t = n*(n + 1)/2;
        int divs = 0;
        for(int d = 1; d*d <= t; d++)
        {
            if(t % d == 0)
                divs +=2;
            if(t == d * d)
                divs--;
        }
        if(divs > 500)
        {
            cout << t << endl;
            return 0;
        }
    }
}