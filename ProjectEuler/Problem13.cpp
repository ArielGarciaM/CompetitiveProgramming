#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e10;

int main()
{
    freopen("input13.in", "r", stdin);
    string input;
    vector<long long> nums;
    while(getline(cin, input))
    {
        nums.push_back(stoll(input.substr(input.length() - 10, 10)));
    }
    long long ans = 0;
    for(auto num : nums)
        ans += num;
    cout << ans << endl;
}