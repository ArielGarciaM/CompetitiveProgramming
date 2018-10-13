#include<bits/stdc++.h>
using namespace std;

vector<int> G[80000];
int vist[80000];

void dfs(int src)
{
    vist[src] = 1;
    for(auto v : G[src])
    {
        if(!vist[v])
            dfs(v);
    }
}

bool intersect(long long a, long long b, long long c, long long d)
{
    //cout << a << " " << b << " " << c << " " << d << endl;
    if((a - b)*(c - d) <= 0ll)
        return false;
    if(max(a, b) < min(c, d) + 1 || min(a, b) + 1 > max(c, d))
        return false;
    //cout << "yes\n";
    return true;
}

int main()
{
    int r, c;
    cin >> r >> c;
    int rect[105][105];
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> rect[i][j];
        }
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(i < r && rect[i][j] == rect[i + 1][j])
            {
                G[c*i + j].push_back(c*i + c + j);
                G[c*i + c + j].push_back(c*i + j);
            }
            if(j < c && rect[i][j] == rect[i][j + 1])
            {
                G[c*i + j].push_back(c*i + j + 1);
                G[c*i + j + 1].push_back(c*i + j);
            }
        }
    }

    int ans = 5;
    memset(vist, 0, sizeof(vist));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(!vist[c*i + j])
            {
                ans++;
                dfs(c*i + j);
            }
        }
    }

    for(int row = 0; row < r - 1; row++)
    {
        for(int col = 0; col < c; col++)
        {
            if(rect[row][col] == rect[row + 1][col])
                continue;
            ans++;
            if(col == c - 1)
                continue;
            if(intersect(rect[row][col], rect[row + 1][col], rect[row][col + 1], rect[row + 1][col + 1]))
                ans--;
        }
    }

    //int subs = 0;
    //out << ans << endl;

    for(int col = 0; col < c - 1; col++)
    {
        for(int row = 0; row < r; row++)
        {
            if(rect[row][col] == rect[row][col + 1])
                continue;
            ans++;
            if(row == r - 1)
                continue;
            if(intersect(rect[row][col], rect[row][col + 1], rect[row + 1][col], rect[row + 1][col + 1]))
            {
                //subs++;
                ans--;
            }
        }
    }

    //cout << subs << endl;
    cout << ans << endl;
}