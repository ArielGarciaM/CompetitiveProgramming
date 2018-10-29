#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input11.in", "r", stdin);
    long long rect[20][20];
    long long ans = 0;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
            cin >> rect[i][j];
    }
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 17; j++)
            ans = max(ans, rect[i][j]*rect[i][j + 1]*rect[i][j + 2]*rect[i][j + 3]);
    }

    for(int i = 0; i < 17; i++)
    {
        for(int j = 0; j < 20; j++)
            ans = max(ans, rect[i][j]*rect[i + 1][j]*rect[i + 2][j]*rect[i + 3][j]);
    }

    for(int i = 0; i < 17; i++)
    {
        for(int j = 0; j < 17; j++)
            ans = max(ans, rect[i][j]*rect[i + 1][j + 1]*rect[i + 2][j + 2]*rect[i + 3][j + 3]);
    }

    for(int i = 0; i < 17; i++)
    {
        for(int j = 3; j < 20; j++)
            ans = max(ans, rect[i][j]*rect[i + 1][j - 1]*rect[i + 2][j - 2]*rect[i + 3][j - 3]);
    }
    cout << ans << endl;
}