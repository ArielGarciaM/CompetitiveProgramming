#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s, t = "";
        cin >> s;
        for(int i = 2; i < s.length(); i++)
        {
            t += s[i];
        }
        while(t.length() < 4)
            t += '0';
        int n = stoi(t);
        cout << 10000/__gcd(10000, n) << endl;
    }
}