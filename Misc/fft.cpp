#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
const double PI = acos(-1);

vector<cd> fft(vector<cd> &P, bool inv) {
    int n = P.size();
    if(n == 1)
        return P;
    vector<cd> roots(n);
    for(int i = 0; i < n; i++)
        roots[i] = polar(1.0, 2.0*PI*(double)i/(double)n);
    vector<cd> A(n/2), B(n/2);
    for(int i = 0; i < n / 2; i++) {
        A[i] = P[2*i];
        B[i] = P[2*i + 1];
    }
    auto X = fft(A, inv);
    auto Y = fft(B, inv);
    vector<cd> res(n);
    for(int i = 0; i < n/2; i++) {
        cd w;
        if(i == 0)
            w = roots[i];
        else
            w = (inv ? roots[n - i] : roots[i]);
        res[i] = X[i] + w*Y[i];
        res[i + n/2] = X[i] - w*Y[i];
    }
    return res;
}

vector<cd> conv(vector<cd> A, vector<cd> B) {
    int n = A.size() + B.size(), L = 32 - __builtin_clz(n);
    n = 1 << L;
    A.resize(n, 0), B.resize(n, 0);
    vector<cd> f = fft(A, false), g = fft(B, false);
    for(int i = 0; i < n; i++)
        f[i] *= g[i];
    g = fft(f, true);
    for(int i = 0; i < n; i++)
        g[i] /= n;
    return g;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<cd> P(n + 1), Q(n + 1);
        for(int i = 0; i <= n; i++)
            cin >> P[i];
        for(int i = 0; i <= n; i++)
            cin >> Q[i];
        auto R = conv(P, Q);
        for(int i = 0; i < 2*n + 1; i++)
            cout << (long long)round(R[i].real()) << " ";
        cout << '\n';
    }
}