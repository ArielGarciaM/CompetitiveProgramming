#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int logn = 10; // Cualquier cosa >= log(MAXN) jala
int A[MAXN]; // Arreglo del que queremos minimos
int rmq[MAXN][logn]; // rmq[n][k] da el mínimo en el rango [n, n + 2^k - 1]

void build() {
    for(int i = 0; i < MAXN; i++)
        rmq[i][0] = A[i];

    for(int nivel = 1; nivel < logn; nivel++) {
        int potencia = 1 << (nivel - 1);
        for(int n = 0; n + 2*potencia - 1 < MAXN; n++) {
            rmq[n][nivel] = min(rmq[n][nivel - 1], rmq[n + potencia][nivel - 1]);
        }
    }
}

int query(int l, int r) {
    int p = 31 - __builtin_clz(r - l + 1); // Bit más significativo
    return min(rmq[l][p], rmq[r - (1 << p) + 1][p]);
}

int main() {
    vector<int> v = {4, 5, 2, 7, 5, 1, 8, 12, 3, 6};
    for(int i = 0; i < 10; i++)
        A[i] = v[i];
    build();
    cout << query(2, 4) << endl;
    cout << query(3, 9) << endl;
}

