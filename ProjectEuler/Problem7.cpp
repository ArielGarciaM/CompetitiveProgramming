#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
int prime[MAXN];
vector<int> primes;

void sieve()
{
    for(int i = 2; i < MAXN; i++)
    {
        if(!prime[i])
        {
            primes.push_back(i);
            for(int j = i; j < MAXN; j += i)
                prime[j] = i;
        }
    }
}

int main()
{
    sieve();
    cout << primes[10000] << endl;
}