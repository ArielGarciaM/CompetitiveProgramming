#include <bits/stdc++.h>
using namespace std;

long long lcm(vector<long long> &A)
{
    if(A.size() == 1)
        return A[0];
    long long x = A.back();
    A.pop_back();
    long long k = lcm(A);
    return x*k/__gcd(x, k);
}

int main()
{
    vector<long long> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    cout << lcm(A) << endl;
}