#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(long long m = 1; m <= n; m++)
        cout << (m - 1)*(m*m*(m + 1) - 8*(m - 2))/2 << endl;
}