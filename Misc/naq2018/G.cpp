#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, ans = "";
    char type;
    cin >> type >> s;
    if(type == 'D')
    {
        for(int i = 0; i < s.length(); i += 2)
        {
            char c;
            int n;
            c = s[i];
            n = s[i + 1] - '0';
            for(int j = 0; j < n; j++)
                ans += c;
        }
    }
    else
    {
        s += '*';
        bool needNew = true;
        char c;
        int count;
        for(int i = 0; i < s.length() - 1; i++)
        {
            if(needNew)
            {
                c = s[i];
                needNew = false;
                count = 1;
            }
            if(s[i + 1] == c)
                count++;
            else
            {
                needNew = true;
                ans += c;
                ans += to_string(count);
            }
        }
    }
    cout << ans << endl;
}