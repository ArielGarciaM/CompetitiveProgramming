#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(true)
    {
        int h;
        cin >> h;
        if(!h)
            break;
        int mx = h;
        while(h > 1)
        {
            h = (h % 2) ? 3*h + 1 : h/2;
            mx = max(h, mx);
        }
        cout << mx << endl;
    }
}