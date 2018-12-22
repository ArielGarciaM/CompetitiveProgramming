#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define LL long long int
#define ABS(x) ((x)<0?-(x):(x))
#define rep(i,a,b) for(long long int i=(a);i<(b);i++)
#define repr(i,a,b) for(long long int i=(a);i>=(b);i--)

typedef tree<long,null_type,greater<long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    LL n,x,sum=0;
    cin>>n;

    vector<pair<LL,LL> > v;
    vector<LL> ans;

    rep(i,0,n){
        cin>>x;
        sum+=x;
        v.push_back(make_pair(x,i+1));
    }

    sort(v.begin(),v.end());

    rep(i,0,n-1){
        if(sum-v[i].first == 2*v[n-1].first)
            ans.push_back(v[i].second);
    }

    if(sum-v[n-1].first == 2*v[n-2].first)
        ans.push_back(v[n-1].second);

    cout<<ans.size()<<endl;

    rep(i,0,ans.size()){
        cout<<ans[i]<<" ";
    }

    return 0;
}