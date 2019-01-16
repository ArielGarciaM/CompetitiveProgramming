#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> k >> n;
    int amt = (n + 1)/k;
    vector<int> occ(1005);
    vector<string> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        occ[x]++;
    }
    for(int i = 1; i <= k; i++)
    {
        if(abs(occ[i] - amt) > 1)
        {
            cout << "*\n";
            return 0;
        }
        if(occ[i] == amt + 1)
            v.push_back("-" + to_string(i));
        if(occ[i] == amt - 1)
            v.push_back("+" + to_string(i));
    }
    if(v.size() > 2)
    {
        cout << "*\n";
        return 0;
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    cout << endl;
}