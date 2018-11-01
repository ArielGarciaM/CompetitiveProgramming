#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n < 100)
    {
        cout << 1 << endl;
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
    }
    else
    {
        int d = n / 4;
        cout << 3 << endl;
        cout << 4 << endl;
        cout << 1 << " " << d << endl;
        cout << d + 1 << " " << 2*d << endl;
        cout << 2*d + 1 << " " << 3*d << endl;
        cout << 3*d + 1 << " " << n << endl;
        cout << 2 << endl;
        cout << 1 << " "  << 2*d << endl;
        cout << 2*d + 1 << " " << n << endl;
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
    }
}