#include <bits/stdc++.h>
using namespace std;

int modPow(long long a, long long b, long long mod)
{
	//cout << a << " " << b << " " << mod << endl;
	if(b == 0) return 1;
	if(b % 2) return (a*modPow(a, b - 1, mod))%mod;
	else return (modPow(a, b/2, mod)*modPow(a, b/2, mod))%mod;
}

int main()
{
	int isPrime[2010];
	for(int i = 0; i < 2010; i++) isPrime[i] = 1;
	for(int i = 2; i < 2001; i++)
	{
		if(isPrime[i])
		{
			for(int j = 2*i; j < 2001; j += i) isPrime[j] = 0;
		}
	}
	for(int p = 1; p < 2001; p++)
	{
		if(!isPrime[p]) continue;
		long long bound = 10000000*p + 1;
		for(long long q = 2*p + 1; q <= bound; q += 2*p)
		{
			//cout << modPow(2, p, q) << endl;
			if(modPow(2, p, q) == 1) break;
			if(q == bound) cout << p << endl;
		}
	}
}