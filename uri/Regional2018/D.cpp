#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> df;
    int n;
    cin >> n;
    while(n--)
    {
        string s, cur = "";
        cin >> s;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '+' || s[i] == '@')
                break;
            if(s[i] != '.')
                cur += s[i];
        }
        cur += s.substr(s.find("@"));
        df.insert(cur);
    }
    cout << df.size() << endl;
}