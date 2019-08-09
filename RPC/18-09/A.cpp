#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
set<string> store[MAXN];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int s;
        string item;
        cin >> s >> item;
        store[s].insert(item);
    }
    int m;
    cin >> m;
    vector<string> items(m);
    vector<int> seq1(m), seq2(m);
    for(int i = 0; i < m; i++)
        cin >> items[i];
    int spt = 0, ipt = 0;
    while(ipt != m) {
        while(spt < n && !store[spt].count(items[ipt]))
            spt++;
        if(spt == n) {
            cout << "impossible\n";
            return 0;
        }
        seq1[ipt++] = spt;
    }
    spt = n - 1, ipt = m - 1;
    while(ipt != -1) {
        while(!store[spt].count(items[ipt]))
            spt--;
        seq2[ipt--] = spt;
    }
    for(int i = 0; i < m; i++) {
        if(seq1[i] != seq2[i]) {
            cout << "ambiguous\n";
            return 0;
        }
    }
    cout << "unique\n";
    return 0;
}