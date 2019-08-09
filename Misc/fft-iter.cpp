#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
const double PI = acos(-1);

/* Para NTT:
998244353 = 119*2^23 + 1, raíz primitiva 3.
*/
template<class T>
vector<T> fft(vector<T> P, bool inv) {
    int n = P.size(), logn = __builtin_ctz(n);
    double sgn = (inv ? -1 : 1);
    vector<T> f(n), root(n);
    vector<int> rev(n);
    for(int i = 1; i < n; i++)
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (logn - 1));
    for(int i = 0; i < n; i++) {
        f[i] = P[rev[i]];
        root[i] = polar(1.0, 2.0*PI*(double)i/(double)n);
    }
    for(int k = 1; k < n; k *= 2) {
        for(int i = 0; i < n; i += 2*k) {
            for(int j = 0; j < k; j++) {
                T z;
                if(j == 0) z = f[i + j + k]; 
                else z = (inv ? root[n - j*(n/(2*k))] * f[i + j + k] : root[j*(n/(2*k))] * f[i + j + k]);
                f[i + j + k] = f[i + j] - z;
                f[i + j] = f[i + j] + z;
            }
        }
    }
    return f;
}

int main() {
    vector<cd> P = {3, 2, 0, 0};
    vector<cd> Q = {-5, 3, 0, 0};
    //for(int i = 0; i < 4; i++)
    //    cout << P[i] << " ";
    //cout << endl;
    auto DP = fft(P, false), DQ = fft(Q, false);
    //for(int i = 0; i < 4; i++)
    //    cout << DP[i] << " ";
    //cout << endl;
    vector<cd> R(4);
    for(int i = 0; i < 4; i++)
        R[i] = DP[i] * DQ[i];
    for(int i = 0; i < 4; i++)
        cout << R[i] << " ";
    cout << endl;
    auto prod = fft(R, true);
    for(int i = 0; i < 4; i++)
        cout << round(prod[i].real())/4.0 << " ";
}