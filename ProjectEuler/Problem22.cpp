#include <bits/stdc++.h>
using namespace std;

long long score(string s)
{
    long long ret = 0;
    for(auto c : s)
        ret += (c - 'A' + 1);
    return ret;
}

int main()
{
    freopen("input22.in", "r", stdin);
    string s, sanit = "";
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if('A' <= c && c <= 'Z') sanit += c;
        else sanit += ' ';
    }
    vector<string> v;
    stringstream ss(sanit);
    while(ss >> s)
        v.push_back(s);
    sort(v.begin(), v.end());
    long long ans = 0;
    for(long long i = 0; i < v.size(); i++)
        ans += (i + 1)*score(v[i]);
    cout << ans << endl;
}