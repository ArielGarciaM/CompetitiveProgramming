#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if(a == 0 && b == 0)
    {
        cout << "Not a moose\n";
        return 0;
    }
    cout << ((a == b) ? "Even " : "Odd ") << 2*max(a, b) << endl;
}