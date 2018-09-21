#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int board[102][102];
	for(int lay = 1; lay <= (N + 1)/2; lay++)
	{
		int guy = (lay % 9);
		if(!guy) guy = 9;
		for(int i = lay - 1; i < N - lay + 1; i++) board[lay - 1][i] = board[N - lay][i] = guy;
		for(int i = lay - 1; i < N - lay + 1; i++) board[i][lay - 1] = board[i][N - lay] = guy;
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++) cout << board[i][j];
		cout << endl;
	}
}