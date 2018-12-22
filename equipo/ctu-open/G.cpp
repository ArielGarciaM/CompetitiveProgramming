#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = abs(a - c) + abs(b - d);
    cout << ((x % 2) ? "white" : "black") << endl;
}