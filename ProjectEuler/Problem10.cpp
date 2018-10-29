#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
int prime[MAXN];
vector<int> primes;
long long ans = 0;

void sieve()
{
    for(int i = 2; i < MAXN; i++)
    {
        if(!prime[i])
        {
            if(i < 2000000) ans += i;
            primes.push_back(i);
            for(int j = i; j < MAXN; j += i)
                prime[j] = i;
        }
    }
}

int main()
{
    sieve();
    cout << ans << endl;
}