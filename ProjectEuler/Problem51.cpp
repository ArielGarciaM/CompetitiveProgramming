#include <bits/stdc++.h>
using namespace std;

const int MAXP = 1e7;
int prime[MAXP];

void sieve()
{
    for(int p = 2; p < MAXP; p++)
    {
        if(!prime[p])
        {
            for(int i = 2*p; i < MAXP; i += p)
                prime[i] = p;
        }
    }
}

int convert(int n, int mask, int digit)
{
    string s = to_string(n);
    for(int i = s.length() - 1; i >= 0; i--, mask /= 2)
    {
        if(mask % 2)
            s[i] = ('0' + digit);
    }
    return stoi(s);
}

vector<int> guys;

int find()
{
    int mn = 999999;
    for(int n = 100000; n < 1000000; n++)
    {
        if(prime[n])
            continue;
        for(int mask = 1; mask < 64; mask++)
        {
            guys.clear();
            int ct = 0;
            for(int d = 0; d <= 9; d++)
            {
                int x = convert(n, mask, d);
                if(!prime[x] && (x >= 100000))
                {
                    ct++;
                    guys.push_back(x);
                }
            }
            if(ct >= 8)
            {
                mn = min(mn, guys[0]);
            }
        }
    }
    return mn;
}

int main()
{
    auto startTime = clock();
    sieve();
    cout << find() << endl;
    for(auto x : guys)
        cout << x << " ";
    cout << endl;
    cout << "Time: " << fixed << setprecision(4) << ((double)(clock() - startTime)/CLOCKS_PER_SEC) << "s\n";
}