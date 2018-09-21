#include<bits/stdc++.h>
using namespace std;

void extract(string S, vector<int> &V)
{
	string str = "";
	for(int i = 0; i < S.length(); i++)
	{
		if(S[i] == ' ')
		{
			V.push_back(stoi(str));
			str = "";
		}
		else str += S[i];
	}
	V.push_back(stoi(str));
}

int main()
{
	int T;
	cin >> T;
	cin.ignore(256, '\n');
	while(T--)
	{
		vector<int> V;
		string s;
		getline(cin, s);
		// cout << s << endl;
		extract(s, V);
		int n = V.size();
		int mx = -1;
		for(int i = 0; i < n; i++) mx = max(mx, V[i]);
		int card = 0;
		for(int i = 0; i < n; i++)
		{
			if(V[i] == mx) card++;
		}
		if(card == 1)
		{
			for(int i = 0; i < n; i++)
			{
				if(V[i] == mx)
				{
					cout << n - i << endl;
				}
			}
		}
		else
		{
			vector<int> maxes;
			int lo, hi;
			for(int i = 0; i < n; i++)
			{
				if(V[i] == mx) maxes.push_back(i);
			}
			if(card % 2) maxes.push_back(n);
			int ans = 0;
			for(int i = 0; i < maxes.size(); i += 2)
			{
				ans += maxes[i + 1] - maxes[i] + 1;
			}
			if(card % 2) ans--;
			cout << ans << endl;
		}
	}
}