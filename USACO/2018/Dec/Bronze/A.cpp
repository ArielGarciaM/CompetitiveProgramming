#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int cap[3], milk[3];
    for(int i = 0; i < 3; i++)
        cin >> cap[i] >> milk[i];
    int cur = 0;
    for(int turn = 0; turn < 100; turn++) {
        int pour = min(milk[cur], cap[(cur + 1)%3] - milk[(cur + 1)%3]);
        milk[cur] -= pour;
        cur = (cur + 1)%3;
        milk[cur] += pour;
    }
    cout << milk[0] << endl;
    cout << milk[1] << endl;
    cout << milk[2] << endl;
}