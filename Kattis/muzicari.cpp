#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, T;
    cin >> T >> N;
    int a[510];
    for(int i = 1; i <= N; i++)
        cin >> a[i];
    short dp[510][5010];
    pair<bool, short> prev[510][5010];
    for(int i = 0; i < 510; i++)
    {
        for(int j = 0; j < 5010; j++)
            dp[i][j] = 0;
    }
    for(int num = 1; num <= N; num++)
    {
        for(int bnd = 0; bnd <= T; bnd++)
        {
            int ifNotIn = dp[num - 1][bnd];
            int ifIn = -1;
            if(bnd - a[num] >= 0)
                ifIn = dp[num - 1][bnd - a[num]] + a[num];
            if(ifNotIn >= ifIn)
            {
                dp[num][bnd] = dp[num - 1][bnd];
                prev[num][bnd] = make_pair(false, bnd);
            }
            else
            {
                dp[num][bnd] = dp[num - 1][bnd - a[num]] + a[num];
                prev[num][bnd] = make_pair(true, bnd - a[num]);
            }
        }
    }
    vector<int> fst, snd;
    int t = T;
    for(int i = N; i >= 1; i--)
    {
        if(prev[i][t].first)
            fst.push_back(i);
        else
            snd.push_back(i);
        t = prev[i][t].second;
    }
    int start[510], cnt = 0;
    for(int mu : fst)
    {
        start[mu] = cnt;
        cnt += a[mu];
    }
    cnt = 0;
    for(int mu : snd)
    {
        start[mu] = cnt;
        cnt += a[mu];
    }
    for(int i = 1; i <= N; i++)
        cout << start[i] << " ";
    cout << endl;
}