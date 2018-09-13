#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	while(cin >> N)
	{
	    //cout << N << endl;
		int x;
	    //cout << "hola\n";
		cin >> x;
		//cout << x << endl;
		int num = (1<<N) - x;
		//cout << num << endl;
		string ans;
		int lsb;
		for(lsb = N - 1; lsb >= 0; lsb--)
		{
			if((1<<lsb) & num) break;
		}
		lsb--;
		//cout << lsb << endl;
		while(lsb >= 0)
		{
		    //cout << (1<<lsb) << endl;
			if((1 << lsb) & num) ans += 'R';
			else ans += 'L';
			lsb--;
		}
		cout << "Instructions: " << ans << endl;
	}
}