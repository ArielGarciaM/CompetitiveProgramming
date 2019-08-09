#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pt;

const int MAXC = 1e6 + 5;
int h[MAXC];

long long isect(pt p1, pt p2) {
    if(p1.first > p2.first)
        swap(p1, p2);
    long long x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
    long long d = x2 - x1;
    long long aux = (-x1*(y2 - y1) + y1*(x2 - x1));
    if(aux < 0)
        return 0ll;
    aux = (aux + d - 1)/d;
    return max(aux, 0ll);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(2*n);
    for(int i = 0; i < 2*n; i++)
        cin >> v[i];
    int cur = 0;
    for(int i = v[0] + 1; i < 1e6 + 2; i++) {
        if(cur % 2)
            h[i] = max(0, h[i - 1] - 1);
        else
            h[i] = h[i - 1] + 1;
        if(i == v[cur + 1])
            cur++;
    }
    int x;
    cin >> x;
    pt pos = {x, h[x]};
    long long mh = 1e18;
    for(int i = 0; i < 2*n; i++) {
        if(v[i] != x)
            mh = min(mh, isect(pos, pt{v[i], h[v[i]]}));
    }
    cout << mh << endl;
}