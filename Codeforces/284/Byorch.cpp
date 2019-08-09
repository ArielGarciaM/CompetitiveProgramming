
 #include <bits/stdc++.h>
using namespace std;
 
int t[5010];
int p[5010];

 
double eps = 1e-8;
int n,T;
int timee = 0;
 
const double T_PI = 2.0*acos(-1);
typedef complex<double> C;

C mul(const C &x, const C &y) {
    double rx = x.real(), ix = x.imag(), ry = y.real(), iy = y.imag();
    return C(rx*ry - ix*iy, rx*iy + ix*ry);
}

void fft(vector<C> &f, vector<C> &root, vector<int> &rev) {
    int n = f.size();
    for(int i = 0; i < n; i++)
        if(i < rev[i]) swap(f[i], f[rev[i]]);
    for(int k = 1; k < n; k <<= 1) {
        for(int i = 0; i < n; i += 2*k) {
            for(int j = 0; j < k; j++) {
                C z = mul(root[j + k], f[i + j + k]);
                f[i + j + k] = f[i + j] - z;
                f[i + j] = f[i + j] + z;
            }
        }
    }
}

vector<double> conv(vector<double> &A, vector<double> &B) {
    int sz = A.size() + B.size() - 1, L = 32 - __builtin_clz(sz), n = 1 << L;
    vector<C> in(n), out(n), root(n);
    for(int i = 0; i < A.size(); i++) in[i].real(A[i]);
    for(int i = 0; i < B.size(); i++) in[i].imag(B[i]);
    for(int i = 0; i < n / 2; i++)
        root[i + n/2] = polar(1.0, T_PI*(double)i/n);
    for(int i = n/2 - 1; i >= 0; i--)
        root[i] = root[i << 1];
    vector<int> rev(n);
    for(int i = 1; i < n; i++)
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (L - 1));
    fft(in, root, rev);
    for(int i = 0; i < n; i++) {
        C z = in[i], zc = in[-i & (n - 1)];
        out[i] = mul(zc, zc) - conj(mul(z, z));
    }
    fft(out, root, rev);
    vector<double> res(sz);
    for(int i = 0; i < sz; i++) res[i] = out[i].imag()/(4.0*n);
    return res;
}
 
 
 
int main(){
    scanf("%d %d",&n,&T);
    for(int i = 0;i<n;i++){
        scanf("%d %d",&p[i],&t[i]);
    }
    double res = 0;
    vector<double> R;
    R.push_back(1);
    for(timee = 0;timee<n;timee++){
        vector<double> P;
        double pr = 0.01*p[timee];
        double prob = pr;
        double sum = 0;
        for(int i = 0;i< t[timee] && i < T - timee;i++){
            if( i == t[timee] - 1) P.push_back(1 - sum);
            else{
                P.push_back(prob);
                sum += prob;
                prob *= (1 - pr);
            }
        }
        if(P.empty()) P.push_back(0);
        R = conv(R,P);
        while(R.size() > max(T - timee, 1)) R.pop_back();
        R.resize(R.size());
        for(int j = 0;j<T - timee && j < R.size() ;j++){
            res += R[j];
        }
    }
    printf("%.9f\n",res);
 
}