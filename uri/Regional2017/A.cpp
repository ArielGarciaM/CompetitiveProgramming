#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pt {
    ll x, y;
};

const int MAXN = 14;
double memo[(1 << MAXN)][MAXN];
double dist[MAXN][MAXN];

double dp(int msk, int s) {
    if(memo[msk][s] < -0.5) {
        double ans = 1e18;
        for(int b = 0; b < MAXN; b++) {
            if(b == s) continue;
            if(msk & (1 << b))
                ans = min(ans, dist[s][b] + dp(msk ^ (1 << s), b));
        }
        memo[msk][s] = ans;
    }
    return memo[msk][s];
}

double toSeg(pt A, pt B, pt C) {
    // y - By = ((Cy - By)/(Cx - Bx))*(x - Bx)
    // ((Cx - Bx)/(Cy - By))(y - By) = x - Bx;
    double x = (double)B.x + (((double)(C.x - B.x))*(A.y - B.y))/((double)(C.y - B.y));
    //cout << fabs(x - (double)(A.x)) << endl;
    return fabs(x - (double)(A.x));
}

double calcDist(vector<pt> A, vector<pt> B) {
    int al, ar, bl, br, pt = 1;
    ll my = 0;
    for(auto& P : A) my = max(my, P.y);
    while(A[pt].y != my) pt++;
    ar = pt;
    while(A[pt].y == my) pt++;
    al = pt - 1;
    pt = 1;
    while(B[pt].y != my) pt++;
    br = pt;
    while(B[pt].y == my) pt++;
    bl = pt - 1;

    for(auto& p : B)
        p.x += (400000000ll);

    int bpos = B.size();
    double di = 1e9;
    for(int apos = 1; apos <= ar; apos++) {
        auto P = A[apos];
        while(P.y > B[bpos - 1].y)
            bpos--;
        di = min(di, toSeg(P, B[bpos - 1], B[bpos % (B.size())]));
    }
    int apos = 1;
    for(bpos = B.size(); bpos >= bl; bpos--) {
        auto P = B[bpos%(B.size())];
        while(P.y > A[apos + 1].y)
            apos++;
        di = min(di, toSeg(P, A[apos], A[apos + 1]));
    }
    double am = -1e9, bm = -1e9;
    for(int i = 0; i < A.size(); i++)
        am = max(am, (double)A[i].x);
    for(int i = 0; i < B.size(); i++)
        bm = max(bm, (double)B[i].x);
    //cout << am << " " << bm << " " << di << endl;
    return (bm - di - am);
}

vector<pt> poly[MAXN];
int leftB[MAXN], rightB[MAXN], len[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        ll my = 0, mnx = 1e9, mxx = -1e9;
        for(int j = 0; j < k; j++) {
            ll x, y;
            cin >> x >> y;
            poly[i].push_back({x, y});
            my = max(my, y);
            mnx = min(mnx, x);
            mxx = max(mxx, x);
        }
        len[i] = mxx - mnx;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j)
                dist[i][j] = calcDist(poly[i], poly[j]);
            //cout << i << " " << j << " " << dist[i][j] << endl;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (1 << n); j++)
            memo[j][i] = -1.0;
        memo[(1 << i)][i] = 0.0;
    }

    double ans = 1e12;
    for(int i = 0; i < n; i++)
        ans = min(ans, dp((1 << n) - 1, i) + len[i]);
    cout << fixed << setprecision(3) << ans << endl;
}