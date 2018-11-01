#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int blk = 0;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == '1')
            blk++;
    }
    cout << ((s[0] - '0' == blk % 2) ? "YES\n" : "NO\n");
}