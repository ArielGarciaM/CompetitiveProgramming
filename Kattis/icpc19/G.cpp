#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5, MAXL = 20;
int n, q, lev, nxt[MAXN][MAXL], SA[MAXN], tSA[MAXN], ord[MAXN], val[MAXN], nval[MAXN];
char name[MAXN];

bool cmp(int a, int b) {
    if(val[SA[a]] != val[SA[b]]) return val[SA[a]] < val[SA[b]];
    return val[nxt[SA[a]][lev]] < val[nxt[SA[b]][lev]];
}

void buildSA() {
    iota(SA, SA + n + 1, 0);
    for(int i = 0; i <= n; i++) val[i] = name[i];
    lev = 0;
    do {
        iota(ord, ord + n + 1, 0);
        sort(ord, ord + n + 1, cmp);
        for(int i = 0; i <= n; i++) tSA[i] = SA[ord[i]];
        nval[tSA[0]] = 0;
        for(int i = 1; i <= n; i++) {
            if(val[tSA[i]] == val[tSA[i - 1]] && val[nxt[tSA[i]][lev]] == val[nxt[tSA[i - 1]][lev]])
                nval[tSA[i]] = nval[tSA[i - 1]];
            else
                nval[tSA[i]] = nval[tSA[i - 1]] + 1;
        }
        for(int i = 0; i <= n; i++) {
            SA[i] = tSA[i];
            val[i] = nval[i];
        }
        lev++;
    } while(lev < MAXL);
}

bool pfx(string &s, int pos) {
    int pt = 0, qt = SA[pos];
    while(pt < s.length()) {
        if(s[pt] != name[qt])
            return false;
        pt++;
        qt = nxt[qt][0];
    }
    return true;
}

bool ge(string &s, int pos) {
    int pt = 0, qt = SA[pos];
    //cout << s << " " << pos << " " << qt << endl;
    while(pt < s.length()) {
        if(s[pt] != name[qt]) {
            if(s[pt] > name[qt])
                return true;
            return false;
        }
        pt++;
        qt = nxt[qt][0];
    }
    return true;
}

bool le(string &s, int pos) {
    int pt = 0, qt = SA[pos];
    while(pt < s.length()) {
        if(s[pt] != name[qt]) return s[pt] <= name[qt];
        pt++;
        qt = nxt[qt][0];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    name[0] = '$';
    nxt[0][0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> name[i] >> nxt[i][0];
    for(int l = 1; l < MAXL; l++)
        for(int i = 0; i <= n; i++)
            nxt[i][l] = nxt[nxt[i][l - 1]][l - 1];
    buildSA();
    /*for(int i = 0; i <= n; i++) {
        int s = SA[i];
        do {
            cout << name[s];
            s = nxt[s][0];
        } while(s != 0);
        cout << " " << val[i] << endl;
    }*/
    while(q--) {
        string s;
        cin >> s;
        int fst, lst, lo = 0, hi = n;
        while(lo < hi) {
            int mi = (lo + hi)/2;
            if(le(s, mi))
                hi = mi;
            else
                lo = mi + 1;
        }
        fst = lo;
        //cout << "first: " << fst << endl;
        lo = 0;
        hi = n;
        while(lo < hi) {
            int mi = (lo + hi + 1)/2;
            if(ge(s, mi))
                lo = mi;
            else
                hi = mi - 1;
        }
        lst = lo;
        //cout << lst << " " << fst << endl;
        if(pfx(s, fst))
            cout << lst - fst + 1 << '\n';
        else
            cout << "0\n";
    }
}