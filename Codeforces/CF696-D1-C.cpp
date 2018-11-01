/*
Author: Ariel Garcia

Idea: Let p_i be the probability of having the key in the left cup, and q_i the probability
of having it in the middle cup, after i turns. Through easy probability we find that
q_(i + 1) = p_i and p_(i + 1) = (p_i + q_i)/2 for each i. We know that 2p_i + q_i = 1 (the
probability of having the key in the left cup is the same as the right). This gives us
q_(i + 1) = (1 - q_i)/2. Now we can solve this recurrence by standard methods to find

q_n = (2^(n - 1) + (-1)^n)/(3*2^(n - 1))

And it is easy to verify that the gcd of the numerator and the denominator is 3. It suffices
to consider the result modulo 10^9 + 7, and by Fermat's Little Theorem it suffices to consider
n modulo 10^9 + 6.
*/

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long PMOD = MOD - 1;

long long modpow(long long a, long long b)
{
    b = ((b % PMOD) + PMOD) % PMOD;
    if(b == 0)
        return 1;
    if(b % 2)
        return (a * modpow(a, b - 1))%MOD;
    long long p = modpow(a, b/2);
    return (p * p)%MOD;
}

long long inv(long long n)
{
    return modpow(n, MOD - 2);
}

int main()
{
    long long n = 1;
    bool even = false;
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        long long a;
        cin >> a;
        if(a % 2 == 0)
            even = true;
        a %= PMOD;
        n = (n * a)%PMOD;
    }
    long long x, y;
    if(even)
    {
        x = modpow(2, n - 1);
        x = (x + 1)%MOD;
        x = (x * inv(3))%MOD;
        y = modpow(2, n - 1);
    }
    else
    {
        x = modpow(2, n - 1);
        x = (x + MOD - 1)%MOD;
        x = (x * inv(3))%MOD;
        y = modpow(2, n - 1);
    }
    cout << x << "/" << y << endl;
}