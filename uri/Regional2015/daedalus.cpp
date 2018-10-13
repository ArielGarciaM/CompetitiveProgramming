#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vals[5] = {1, 10, 100, 1000, 10000};
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for(int rd = 0; rd < m; rd++)
    {
        int b, sum = 0, d;
        cin >> b;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            if(i == 0)
                d = x;
        }
        for(int i = 4; i >= 0; i--)
        {
            if(sum + vals[i] - d <= b)
            {
                //cout << sum << " " << vals[i] << endl;
                ans += (sum <= b) ? (vals[i] - d) : vals[i];
                break;
            }
        }
    }
    cout << ans << endl;
}