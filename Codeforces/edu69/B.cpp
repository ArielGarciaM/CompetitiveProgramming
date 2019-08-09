#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vi = vector<int>;
 
const int MAX = 3e5+10;
const int TAM = 11;
const ll INF = 1e15;
 
ll a[MAX];
ll B[MAX];
ll L[MAX][TAM];
ll R[MAX][TAM];
 
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    while( n%m){
        a[n] = 0;
        n++;
    }
    int bl = n/m;
    ll res = 0;
    for(int i = 0;i<bl;i++){
        for( int j = 0;j<m;j++){
            B[i] += a[i*m+j];
        }
        for(int j = 1;j<=m;j++){
            R[i][j] = R[i][j-1] + a[i*m+j-1];
            L[i][j] = L[i][j-1] + a[(i+1)*m - j];
        }
        ll endbest = 0;
        for(int j=0;j<m;j++){
            if( endbest <= 0) endbest = a[i*m+j];
            else endbest = endbest + a[i*m+j];
            res = max(res,endbest - k);
        }
        B[i] -= k;
    }
    for(int l=0;l<m;l++){
        ll endmax;
        int start = 0;
        if( l ){
            start++;
            endmax = L[0][l];
        }
        else{
            endmax =0;
        }
        for(int i=start;i<bl;i++){
            for(int r=0;r<=m;r++){
                if( l + r == 0) res = max(res,endmax + R[i][r]);
                else{
                    if( l + r <= m ) res = max(res,endmax + R[i][r] -k);
                    else res = max(res,endmax + R[i][r] - 2*k);
                }
            }
            endmax = max( endmax + B[i], L[i][l]);
        }
    }
    printf("%lld\n",res);
}
