#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

ii q = {{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{1,1},{1,2},{1,3},{1,4},{1,5},{2,2},{2,3},{2,4},{2,5},{3,3},{3,4},{3,5},{4,4},{4,5},{5,5}};
int a[6] = {4, 8, 16, 15, 23, 42};

bool check(int n) {
    vector<ii> qry(4);
    for(int i = 0; i < 4; i++) {
        qry[i] = n % 21;
        n /= 21;
    }
    ll x = 10000;
}

int main() {
    int ans = 0;
    for(int i = 0; i < 21*21*21*21; i++) {
        if(check(i))
            ans++;
    }
}