#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = (n - 1)/12;
    if(n > 30)
    {
        cout << "0 0\n";
        for(int i = 0; i < k; i++)
        {
            cout << "0 " << 4*i + 1 << endl;
            cout << "0 " << 4*i + 2 << endl;
            cout << "0 " << 4*i + 3 << endl;
            cout << "0 " << 4*i + 4 << endl;
            cout << "-1 " << 4*i + 2 << endl;
            cout << "-1 " << 4*i + 3 << endl;
            cout << 4*i + 1 << " 0\n";
            cout << 4*i + 2 << " 0\n";
            cout << 4*i + 3 << " 0\n";
            cout << 4*i + 4 << " 0\n";
            cout << 4*i + 2 << " -1\n";
            cout << 4*i + 3 << " -1\n";
        }
        int m = n - 1 - 12*k;
        if(m >= 6)
        {
            cout << "0 " << 4*k + 1 << endl;
            cout << "0 " << 4*k + 2 << endl;
            cout << "0 " << 4*k + 3 << endl;
            cout << "0 " << 4*k + 4 << endl;
            cout << "-1 " << 4*k + 2 << endl;
            cout << "-1 " << 4*k + 3 << endl;
            m -= 6;
        }
        for(int i = 0; i < m; i++)
        {
            cout << "100000000 " << i << endl; 
        }
    }
    else
    {
        for(int i = 0; i < n/2; i++)
        {
            cout << "0 " << i << endl;
        }
        for(int i = n/2; i < n; i++)
        {
            cout << "3 " << i - n/2 << endl;
        }
    }
}