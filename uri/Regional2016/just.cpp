#include<bits/stdc++.h>
using namespace std;

int sv[100000];
vector<int> primes;

void sieve()
{
    for(int i = 2; i < 100000; i++)
    {
        if(sv[i])
            continue;
        primes.push_back(i);
        for(int j = 2*i; j < 100000; j += i)
        {
            sv[j] = 1;
        }
    }
}

bool isPrime(int n)
{
    for(int p : primes)
    {
        if(n == p)
            return true;
        if(n % p == 0)
            return false;
    }
    return true;
}

int main()
{
    sieve();
    int n;
    cin >> n;
    for(int i = n; i >= 1; i--)
    {
        if(isPrime(i))
        {
            cout << i << endl;
            return 0;
        }
    }
}