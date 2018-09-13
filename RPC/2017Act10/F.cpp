#include <bits/stdc++.h>
using namespace std;

vector<int> G[1000];
char mapa[32][32];
vector<int> vist(1000, -1);

int dfs(int source)
{
	int ans = 1;
	vist[source] = 0;
	for(int v : G[source])
	{
		if(vist[v] == -1)
		{
			vist[v] = 0;
			ans += dfs(v);
		}
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int R, C;
		cin >> R >> C;
		for(int i = 0; i < R; i++)
		{
			string s;
			cin >> s;
			for(int j = 0; j < C; j++)
			{
				char c = s[j];
				mapa[i][j] = c;
			}
		}
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				if(mapa[i][j] == '0')
				{
					if(i < R - 1 && mapa[i + 1][j] == '0')
					{
						G[C*i + j].push_back(C*(i + 1) + j);
						G[C*(i + 1) + j].push_back(C*i + j);
					}
					if(j < C - 1 && mapa[i][j + 1] == '0')
					{
						G[C*i + j].push_back(C*i + j + 1);
						G[C*i + j + 1].push_back(C*i + j);
					}
				}
			}
		}
		int source = -1;
		for(int i = 0; i < R - 1; i++)
		{
			if(mapa[i][0] == '0')
			{
				source = C*i;
				break;
			}
			if(mapa[i][C - 1] == '0')
			{
				source = C*i + C - 1;
				break;
			}
		}
		for(int j = 0; j < C - 1; j++)
		{
			if(source > -1) break;
			if(mapa[0][j] == '0')
			{
				source = j;
				break;
			}
			if(mapa[R - 1][j] == '0')
			{
				source = C*(R - 1) + j;
				break; 
			}
		}
		cout << dfs(source) << endl;
	}
}