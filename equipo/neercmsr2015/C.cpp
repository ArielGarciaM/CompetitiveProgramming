#include <bits/stdc++.h>
using namespace std;

char query(int x, int y) {
    cout << x << " " << y << '\n';
    cout.flush();
    char c;
    if(cin >> c)
        return c;
    exit(0);
}

int main() {
    // Determina x
    query(0, 0);
    int p = 1;
    while(query(p, 0) == '1') {
        p <<= 1;
        if(p > 1000000000)
            p = 1000000000;
    }
    // x está entre 0 y p
    int lo = 0, hi = p;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        query(lo, 0);
        char c = query(hi, 0);
        if(c == '1') {
            // Mueve a la derecha
            lo = mi + 1;
        }
        else
            hi = mi;
    }
    int x = lo;
    query(0, 0);
    p = 1;
    while(query(0, p) == '1') {
        p <<= 1;
        if(p > 1000000000)
            p = 1000000000;
    }
    // y está entre 0 y p
    lo = 0, hi = p;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        query(0, lo);
        char c = query(0, hi);
        if(c == '1') {
            // Mueve arriba
            lo = mi + 1;
        }
        else
            hi = mi;
    }
    int y = lo;
    cout << "A " << x << " " << y << '\n';
    cout.flush();
}