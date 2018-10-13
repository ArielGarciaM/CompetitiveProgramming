#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count[10];
    for(int i = 0; i < 10; i++)
        count[i] = 2;
    string s;
    cin >> s;
    long long ans = 0ll;
    for(int coin = 0; coin <= s.length(); coin++)
    {
        if(coin > 0)
            count[s[coin - 1] - '0']--;
        bool b = true;
        for(int i = 0; i < 10; i++)
        {
            if(count[i] < 0)
            {
                b = false;
                break;
            }
        }
        if(!b)
            break;

        if(coin == s.length())
        {
            cout << s << endl;
            return 0;
        }

        int d = -1;
        for(int i = (s[coin] - '0') - 1; i >= 0; i--)
        {
            if(count[i] > 0)
            {
                d = i;
                break;
            }
            if(i == 0)
                b = false;
        }
        if(!b)
            continue;

        int temp[10];
        for(int i = 0; i < 10; i++)
            temp[i] = count[i];

        string t = "";
        for(int i = 0; i < coin; i++)
            t += s[i];

        temp[d]--;
        t += to_string(d);
        d = 9;
        for(int i = coin + 1; i < s.length(); i++)
        {
            while(temp[d] <= 0)
                d--;
            t += to_string(d);
            temp[d]--;
        }
        ans = max(ans, stoll(t));
    }
    cout << ans << endl;
}