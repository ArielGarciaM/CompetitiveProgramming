#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){return a?gcd(b %a, a):b;}

int main()
{
	long long n, m, k;
	cin >> n >> m >> k;
	if((2ll*m*n) % k)
	{
		cout << "NO\n";
		return 0;
	}
	long long d = gcd(2ll*m*n/k, n);
	long long s = (2ll*m*n/k)/d;
	if(s > m)
	{
		cout << "NO\n";
		return 0; 
	}
	cout << "YES" << endl;
	cout << "0 0" << endl;
	cout << d << " 0" << endl;
	cout << "0 " << (2ll*m*n/k)/d << endl;
}

/*
ab/2 = mn/k

ab = 2mn/k

k divides 2mn
*/