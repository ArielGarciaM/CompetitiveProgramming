#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        if(k < (n*(n + 1))/2)
        {
            cout << "Too drunk to count\n";
            continue;
        }
        k -= ((n * (n + 1))/2);
        if(k % n)
        {
            cout << "Too drunk to count\n";
            continue;
        }
        cout << n + k/n + 1 << endl;
    }
}