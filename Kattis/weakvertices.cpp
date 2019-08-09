#include <bits/stdc++.h>
using namespace std;

int adj[20][20];

int main() {
    int n;
    while(cin >> n, n >= 0) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> adj[i][j];

        for(int v = 0; v < n; v++) {
            bool weak = true;
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    if(adj[v][i] && adj[v][j] && adj[i][j])
                        weak = false;
                }
            }
            if(weak)
                cout << v << " ";
        }
        cout << endl;
    }
}