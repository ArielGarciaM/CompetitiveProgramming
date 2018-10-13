#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int a[5];
    cin >> t;
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    int ans = 0;
    for(int i = 0; i < 5; i++)
        ans += (a[i] == t) ? 1 : 0;
    cout << ans << endl;
}