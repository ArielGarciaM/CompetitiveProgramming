#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

int main()
{
    string s;
    vector<int> helper;
    int n;
    cin >> n;
    cin >> s;
    int cnt = 0;
    s += 'R';
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'R')
        {
            helper.push_back(cnt + 1);
            cnt = 0;
        }
        else
        {
            cnt = 1;
            while(s[i + 1] == 'L')
            {
                i++;
                cnt++;
            }
        }
    }
    /*for(auto x : helper)
        cout << x << " ";*/
    int ptr = 0;
    vector<int> ans;
    int i = 0;
    while(ans.size() < n)
    {
        ptr += helper[i];
        for(int j = 0; j < helper[i]; j++)
            ans.push_back(ptr - j);
        i++;
    }
    for(auto x : ans)
        cout << x << endl;
}