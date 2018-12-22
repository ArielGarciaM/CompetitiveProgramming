#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100002;

int main()
{
    ll A[MAXN], B[MAXN];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < n; i++)
        cin >> B[i];
    int m = 0;
    ll sa[3], sb[3];
    for(int i = 0; i < n; i++)
    {
        m = (m + 1)%3;
        sa[m] += A[i];
        sb[m] += B[i];
    }
    //cout << sb[0] << " " << sb[1] << " " << sb[2] << endl;
    ll a0 = sa[0]*sb[0] + sa[1]*sb[2] + sa[2]*sb[1], a1 = sa[0]*sb[1] + sa[1]*sb[0] + sa[2]*sb[2], a2 = sa[0]*sb[2] + sa[1]*sb[1] + sa[2]*sb[0];
    cout << a0 << " " << a1 << " " << a2 << endl;
}