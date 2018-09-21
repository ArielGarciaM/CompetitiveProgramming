#include <bits/stdc++.h>
using namespace std;

bool inStr(char c)
{
	return(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('1' <= c && c <= '9'));
}

int main()
{
	string s, ans;
	getline(cin, s);
	ans += '{';
	for(int i = 1; i < s.length() - 1; i++)
	{
		char prev = s[i - 1], curr = s[i], next = s[i + 1];
		if(!inStr(prev) && inStr(curr)) ans += '\"';
		ans += curr;
		if(!inStr(next) && inStr(curr)) ans += '\"';
	}
	ans += '}';
	cout << ans << endl;
}
