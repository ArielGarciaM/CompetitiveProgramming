#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int main()
{
    freopen("input.in", "w", stdout);
    cout << N << " " << 10 << endl;
    vector<int> v;
    for(int i = 1; i <= N; i++)
        v.push_back(i);
    for(int i = 0; i < 10; i++)
    {
        int k = rand()%1000000;
        while(k--)
            next_permutation(v.begin(), v.end());
        for(int x : v)
            cout << x << " ";
        cout << endl;
    }
}