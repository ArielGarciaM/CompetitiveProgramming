#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{
    string s = to_string(n);
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    int mx = 0;
    for(int i = 100; i < 1000; i++)
    {
        for(int j = 100; j < 1000; j++)
        {
            if(isPalindrome(i*j))
                mx = max(mx, i*j);
        }
    }
    cout << mx << endl;
}