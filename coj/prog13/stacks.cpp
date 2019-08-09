#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct st {
    st *ne;
    int sz, top;
    st() { sz = 1; ne = nullptr; top = 0; }
    st(st *_ne, int _top) {
        ne = _ne;
        sz = ne->sz + 1;
        top = _top;
    }
};

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    vector<st*> stacks;
    stacks.push_back(new st());
    int n;
    cin >> n;
    while(n--) {
        int id, type;
        cin >> id >> type;
        if(type == 1) {
            if(stacks[id]->sz == 1) {
                cout << "-1\n";
                stacks.push_back(new st());
            }
            else {
                cout << stacks[id]->top << '\n';
                stacks.push_back(stacks[id]->ne);
            }
        }
        else {
            int va;
            cin >> va;
            stacks.push_back(new st(stacks[id], va));
            cout << stacks.back()->sz - 1 << '\n';
        }
    }
}