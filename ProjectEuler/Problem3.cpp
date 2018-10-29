#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x = 600851475143;
    for(int d = 2;; d++)
    {
        while(x % d == 0)
        {
            x /= d;
            if(x == 1)
            {
                cout << d << endl;
                return 0;
            }
        }
    }
}