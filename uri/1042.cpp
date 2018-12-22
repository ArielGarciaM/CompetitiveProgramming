#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x = min(a, min(b, c)), y = max(a, max(b, c));
    cout << x << endl;
    cout << a + b + c - x - y << endl;
    cout << y << endl;
    cout << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}