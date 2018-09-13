#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	while(cin >> N, N > 0)
	{
		int ans = 0;
		for(int c = 1; c <= N; c++)
		{
			for(int b = 1; b <= c; b++)
			{
				for(int a = 1; a <= b; a++)
				{
					if(a*a + b*b == c*c) ans++;
				}
			}
		}
		cout << ans << endl;
	}
}