#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> abun;
    set<int> sums;
    for(int a = 1; a <= 28123; a++)
    {
        int sum = -a;
        for(int d = 1; d*d <= a; d++)
        {
            if(a % d == 0)
            {
                sum += d;
                sum += a/d;
                if(d*d == a) sum -= d;
            }
        }
        if(sum > a)
            abun.push_back(a);
    }
    cout << abun[0] << endl;
    cout << "cool\n";
    for(int i = 0; i < abun.size(); i++)
    {
        for(int j = 0; j < abun.size(); j++)
        {
            if(abun[i] + abun[j] > 28123) break;
            sums.insert(abun[i] + abun[j]);
        }
    }
    int ans = 0;
    for(int x = 1; x <= 28123; x++)
    {
        if(!sums.count(x))
            ans += x;
    }
    cout << ans << endl;
}