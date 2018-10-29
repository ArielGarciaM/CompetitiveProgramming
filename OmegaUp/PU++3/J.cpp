#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    char rect[105][105];
    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < c; j++)
        {
            rect[i][j] = s[j];
        }
    }
    map<char, int> ct;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            ct[rect[i][j]]++;
        }
    }
    char letter;
    for(auto p : ct)
        if(p.second == 1) letter = p.first;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(rect[i][j] == letter)
            {
                cout << letter << " (" << i + 1 << "," << j + 1 << ")\n";
                return 0;
            }
        }
    }
}