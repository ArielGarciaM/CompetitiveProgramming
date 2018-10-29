#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s = 0, ss = 0;
    for(int x = 1; x <= 100; x++)
    {
        s += x;
        ss += x*x;
    }
    cout << abs(s*s - ss) << endl;
}