#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while(getline(cin, s))
	{
		string sorted = s;
		sort(sorted.begin(), sorted.end());
		bool used[1005];
		memset(used, false, sizeof(used));
		char last = '$';
		string answer = "";
		int n = s.length();
		while(!used[0])
		{
			for(int i = n - 1; i >= 0; i--)
			{
				if(s[i] == last && !used[i])
				{
					used[i] = true;
					last = sorted[i];
					if(last != '$') answer += last;
					break;
				}
			}
		}
		cout << answer << endl;
	}
}