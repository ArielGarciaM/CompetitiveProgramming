#include<bits/stdc++.h>
using namespace std;

long long mcm(long long a, long long b)
{
	return (a * b)/__gcd(a, b);
}

int main()
{
	int n;
	cin >> n;
	long long a;
	cin >> a;
	for(int i = 1; i < n; i++)
	{
		long long b;
		cin >> b;
		a = mcm(a, b);
	}
	cout << a << endl;
}