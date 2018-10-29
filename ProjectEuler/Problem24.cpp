#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i = 1; i < 1000000; i++)
    {
        next_permutation(v.begin(), v.end());
    }
    for(int x : v)
        cout << x;
    cout << endl;
}