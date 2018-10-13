#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, c, s;
    cin >> n >> c >> s;
    s = s % n;
    int loc = 1, ans = 0;
    for(int i = 0; i < c; i++)
    {
        if(loc == s)
            ans++;
        int comm;
        cin >> comm;
        loc = (loc + comm + n)%n;
    }
    if(loc == s)
        ans++;
    cout << ans << endl;
}