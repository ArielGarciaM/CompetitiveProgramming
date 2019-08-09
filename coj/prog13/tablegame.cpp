#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> ii;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e4 + 5;
char c;
int n, D, R, A, money[MAXN];
bool bad[MAXN];

void test_case() {
    memset(bad, false, sizeof bad);
    Tree<int> t;
    for(int i = 1; i <= n; i++) {
        money[i] = D;
        t.insert(i);
    }
    int sz = n, cur = 1, turns = 0;
    while(sz > 1 && turns < n - 1) {
        turns++;
        cin >> c >> R >> A;
        int x = t.order_of_key(cur);
        if(c == 'C')
            x = (x + R)%sz;
        else
            x = (x - R)%sz;
        if(x < 0)
            x += sz;
        int d = *t.find_by_order(x);
        if(sz == 1)
            break;
        cur = d;
        x = t.order_of_key(cur);
        money[d] += A;
        if(money[d] % 2 == 0) {
            int le = (x - 1)%sz, ri = (x + 1)%sz;
            if(le < 0) le += sz;
            int a = *t.find_by_order(le);
            int b = *t.find_by_order(ri);
            bad[a] = true;
            bad[b] = true;
            t.erase(a);
            sz--;
            if(b != a) {
                t.erase(b);
                sz--;
            }
        }
        else {
            int pv = cur, nx;
            if(c == 'C')
                nx = (x + 1)%sz;
            else
                nx = (x + sz - 1)%sz;
            cur = *t.find_by_order(nx);
            t.erase(pv);
            sz--;
        }
    }
    while(turns < n - 1) {
        cin >> c >> R >> A;
        turns++;
    }
    for(int i = 1; i <= n; i++)
        if(!bad[i]) cout << i << " " << money[i] << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    while(cin >> n >> D)
        test_case();
}