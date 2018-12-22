#include <bits/stdc++.h>
using namespace std;

const int MAXL = 6e6;
int Z[MAXL];

void zfunc(const string &s)
{
    int L = 0, R = 0, n = s.length();
    for(int i = 1; i < n; i++)
    {
        Z[i] = (i <= R ? min(Z[i - L], R - i + 1) : 0);
        while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            Z[i]++;
        if(i + Z[i] - 1 > R)
            L = i, R = i + Z[i] - 1;
    }
}

int main()
{
    string s, t;
    while(getline(cin, s))
    {
        getline(cin, t);
        string text = s + '&' + t;
        zfunc(text);
        for(int i = 1; i < text.length(); i++)
        {
            if(Z[i] == s.length())
                cout << i - s.length() - 1 << " ";
        }
        cout << endl;
    }
}