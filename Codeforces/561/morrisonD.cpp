#include <bits/stdc++.h>
using namespace std;
 
int q;
long long a, b, m;
long long secuencia[51], secuencia1[51];
 
long long potencia1(long long s, long long t){
    int cont = 1;
    long long p = s+1;
    while (p <= t){
        p = 2 * p;
        cont++;
    }
    return cont;
}
 
 
int main() {
    cin >> q;
    for (int i= 0; i<q; i++){
        cin >> a >> b >> m;
        if (a == b){
            cout << "1 " << a << endl;
            continue;
        }
        long long r = potencia1(a, b);
        long long z = 1ll << (r-2);
        if (b > (a+m)*z){
            cout << "-1"<< endl;
        }
        else {
            long long residuo = b % z;
            long long k = (b - residuo)/z - a;
            long long copia = residuo;
            for (long long i = r-1; i>=2; i--){
                secuencia[i] = copia % 2;
                copia >>= 1;
            }
            secuencia[r] = 0;
            cout << r << " ";
            secuencia1[1] = a;
            secuencia1[2] = secuencia1[1] + k + secuencia[2];
            cout << secuencia1[1] << " " << secuencia1[2] << " ";
 
            for (long long i = 3; i<=r; i++){
                secuencia1[i] = 2 * secuencia1[i-1] + secuencia[i] - secuencia[i-1];
                cout << secuencia1[i] << " ";
            }
            cout <<endl;
        }
    }
}

g++ morrisonD.cpp -o morrisonD -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
