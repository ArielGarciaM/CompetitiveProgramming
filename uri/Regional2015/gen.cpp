#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("output.out", "w", stdout);
    int r = 100, c = 100;
    int cur = 1;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cur = (13*cur + 2)%109 + 1;
            cout << cur << " ";
        }
        cout << endl;
    }
}