#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        string t = "";
        for(char c : s)
        {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                t += '1';
            else
                t += '0';
        }
        vector<int> onePos;
        for(int i = 0; i < t.length(); i++)
        {
            if(t[i] == '1')
                onePos.push_back(i);
        }
        if(onePos.empty())
        {
            cout << 1 << endl;
            continue;
        }
        if(t[0] == '0')
        {
            cout << 0 << endl;
            continue;
        }
        onePos.push_back(t.length());
        int m = (onePos.size() - 2)/2;
        cout << onePos[m + 1] - onePos[m] << endl;
    }
}