#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	string board[1005];
	for(int i = 0; i < N; i++)
	{
		cin >> board[i];
	}
	string targ;
	cin >> targ;
	long long ans;
	int len = targ.length();
	for(int i = 0; i < N; i++)
	{
		string s = board[i];
		for(int j = 0; j < M; j++)
		{
			if(s.substr(j, len) == targ) ans++;
		}
	}
	string rotBoard[1005];
	for(int i = 0; i < M; i++)
	{
		rotBoard[i] = "";
		for(int j = 0; j < N; j++) rotBoard[i] += board[j][i];
	}
	for(int i = 0; i < M; i++)
	{
		string s = rotBoard[i];
		for(int j = 0; j < N; j++)
		{
			if(s.substr(j, len) == targ) ans++;
		}
	}
	cout << ans << endl;
}