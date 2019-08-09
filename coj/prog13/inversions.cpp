#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

const int INF = 1e9 + 9;
int A[1000005], L[1000005], R[1000005];
ll inv;

inline int readint() {
    string s;
    char c;
    while(true) {
        c = getchar_unlocked();
        if(c > '9' || c < '0') break;
        s += c;
    }
    //cout << s << '\n';
    return stoi(s);
}

void merge(int *A, int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q;
    for(int i = 1; i <= n1; i++)
        L[i] = A[p + i - 1];
    for(int j = 1; j <= n2; j++)
        R[j] = A[q + j];
    L[n1 + 1] = INF;
    R[n2 + 1] = INF;
    int i = 1, j = 1;
    for(int k = p; k <= r; k++) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
            inv += n1 - i + 1;
        }
    }
}

void mergesort(int *A, int p, int r) {
    if(p < r) {
        int q = (p + r)/2;
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    int n;
    while(true) {
        n = readint();
        if(n == 0)
            return 0;

        for(int i = 1; i <= n; i++) A[i] = readint();
        inv = 0;
        mergesort(A, 1, n);
        cout << inv << '\n';
    }
}