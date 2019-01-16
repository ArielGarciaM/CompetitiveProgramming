#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;

template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator==(P p) const { return tie(x,y) == tie(p.x, p.y);}
    P operator-(P p) const {return P(x - p.x, y - p.y); }
    T dot(P p) const {return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
};

template<class P>
bool segmentIntersectionQ(P s1, P e1, P s2, P e2) {
    if(e1 == s1) {
        if(e2 == s2)
            return e1 == e2;
        swap(s1, s2);
        swap(e1, e2);
    }
    P v1 = e1 - s1, v2 = e2 - s2, d = s2 - s1;
    auto a = v1.cross(v2), a1 = d.cross(v1), a2 = d.cross(v2);
    if(a == 0) {
        auto b1 = s1.dot(v1), c1 = e1.dot(v1), b2 = s2.dot(v1), c2 = e2.dot(v1);
        return !a1 && max(b1, min(b2, c2)) <= min(c1, max(b2, c2));
    }
    if(a < 0) { a = -a; a1 = -a1; a2 = -a2; }
    return (0 <= a1 && a1 <= a && 0 <= a2 && a2 <= a);
}

typedef Point<ll> LP;

LP wells[MAXN];
pair<LP, LP> pipes[MAXN];
vector<int> adj[MAXN];
int di[MAXN];

bool bfs(int s) {
    queue<int> q({s});
    di[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(di[v] == -1) {
                di[v] = di[u] + 1;
                q.push(v);
            }
            else {
                //cout << u << " " << v << " " << di[u] << " " << di[v] << endl;
                if(di[u] % 2 == di[v] % 2)
                    return false;
            }
        }
    }
    return true;
}

int main() {
    int w, p;
    cin >> w >> p;
    for(int i = 1; i <= w; i++) {
        ll x, y;
        cin >> x >> y;
        wells[i] = LP(x, y);
    }
    for(int i = 1; i <= p; i++) {
        int w;
        ll x, y;
        cin >> w >> x >> y;
        pipes[i] = make_pair(wells[w], LP(x, y));
    }
    for(int i = 1; i <= p; i++) {
        for(int j = i + 1; j <= p; j++) {
            if(pipes[i].first == pipes[j].first)
                continue;
            if(!segmentIntersectionQ(pipes[i].first, pipes[i].second, pipes[j].first, pipes[j].second))
                continue;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    memset(di, -1, sizeof di);
    for(int v = 1; v <= p; v++) {
        if(di[v] != -1)
            continue;
        if(!bfs(v)) {
            cout << "impossible\n";
            return 0;
        }
    }
    cout << "possible\n";
}