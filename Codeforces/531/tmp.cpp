#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int csort[5001];
    memset(csort, 0, sizeof csort);
    vector<int> aux[5001];
    for(int i=0;i<n;i++){
        int k = arr[i];
        csort[k]++;
        aux[k].push_back(i);
    }
    int color=1;
    int out[n];
    memset(out, 0, sizeof out);
    for(int i=1;i<5001;i++){
        int k = csort[i];
        if(k>m){
            cout<<"NO\n";
            return 0;
        }
        //cout<<i<<":\n";

        for(int j=0;j<aux[i].size();j++){
            //cout<<aux[i][j]<<endl;
            out[aux[i][j]]=color;
            color++;
            if(color==m+1) color=1;
        }
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++){
        if(i!=0) cout<<" ";
        cout<<out[i];
    }

    cout<<endl;
    return 0;
}