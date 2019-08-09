#include <bits/stdc++.h>
using namespace std;

int main() {
    //srand(time(0));
    int n = 7;
    /*for(int i = 0; i < n; i++) {
        int x = random() % 20;
        a[x]++;
    }*/
    for(int t = 0; t < 823543; t++) {
        if(__builtin_popcount(t) == 1)
            cout << t << endl;
        vector<int> a(n);
        int k = t;
        for(int d = 0; d < 7; d++) {
            a[(k % 7)]++;
            k /= 7;
        }
        int extra = 0, x = 0, se = 0;
        for(int i = 0; i < n; i++)
            se += a[i] * i;
        for(int i = 0; i < n; i++) {
            if(a[i] > 1)
                extra += a[i] - 1;
            if(a[i] == 0 && extra) {
                a[i] = 1;
                extra--;
            }
            if(a[i] == 0)
                x++;
        }
        if(n*x >= se) {
            for(int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            for(int i = 0; i < n; i++) {
                if(a[i])
                    cout << "1 ";
                else
                    cout << "-1 ";
            }
            cout << endl;
            cout << "nx = " << n*x << " suma e = " << se << endl;
            cout << "vale verga la vida\n";
            return 0;
        }
    }
}