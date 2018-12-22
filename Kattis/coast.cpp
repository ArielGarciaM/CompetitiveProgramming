#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

char board[1005][1005];
int n, m;
map<pii, int> vist;
vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(pii src)
{
    int ans = 0;
    vist[src] = 1;
    for(auto p : dir)
    {
        int ni = src.first + p.first, nj = src.second + p.second;
        if(ni < 0 || ni > n + 1 || nj < 0 || nj > m + 1)
            continue;
        if(!vist[make_pair(ni, nj)])
        {
            if(board[ni][nj] == '0')
                ans += dfs(make_pair(ni, nj));
            else
                ans++;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m + 2; i++)
        board[0][i] = '0';
    for(int i = 1; i <= n; i++)
    {
        board[i][0] = board[i][m + 1] = '0';
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            board[i][j + 1] = s[j];
    }
    for(int i = 0; i < m + 2; i++)
        board[n + 1][i] = '0';
    /*for(int i = 0; i < n + 2; i++)
    {
        for(int j = 0; j < m + 2; j++)
            cout << board[i][j];
        cout << endl;
    }
    cout << endl;*/
    cout << dfs({0, 0}) << endl; 
}