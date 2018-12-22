#include <bits/stdc++.h>
using namespace std;

int mex(vector<int> &v)
{
    int n = v.size();
    vector<bool> seen(n + 1, false);
    for(auto x : v)
        seen[x] = true;
    for(int i = 0; i <= n; i++)
    {
        if(!seen[i])
            return i;
    }
}

int main()
{
    int gdy[2005];
    gdy[1] = 0;
    for(int n = 2; n <= 2000; n++)
    {
        vector<int> pos(n - 1);
        pos.clear();
        for(int i = 1; i < n; i++)
        {
            int res = (n % i);
            int div = (n / i);
            int x;
            if(res == 0)
            {
                if(div % 2)
                    pos.push_back(gdy[i]);
                else
                    pos.push_back(0);
            }
            else
            {
                if(div % 2)
                {
                    /*if(n == 3)
                        cout << i << " " << gdy[div] << " " << gdy[res] << endl;*/
                    pos.push_back(gdy[i] ^ gdy[res]);
                }
                else
                    pos.push_back(gdy[res]);
            }
        }
        /*cout << n << endl;
        for(auto x : pos)
            cout << x << " ";
        cout << endl;*/
        gdy[n] = mex(pos);
    }
    /*for(int i = 1; i <= 20; i++)
        cout << gdy[i] << endl;*/
    int n, A[2005];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans ^= gdy[A[i]];
    if(ans == 0)
        cout << "Second\n";
    else
        cout << "First\n";
}