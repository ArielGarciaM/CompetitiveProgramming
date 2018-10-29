#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> fib = {1, 2};
    long long ans = 2;
    for(int i = 2;;i++)
    {
        fib.push_back(fib[i - 1] + fib[i - 2]);
        if(fib[i] > 4000000) break;
        if(fib[i]%2 == 1) ans += fib[i];
    }
    cout << ans << endl;
}