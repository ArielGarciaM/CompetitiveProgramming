#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sums[n][2];
    sums[0][0]=arr[0];
    sums[0][1]=0;
    for(int i=1;i<n;i++){
        if(i%2==0){
            sums[i][0]=sums[i-1][0]+arr[i];
            sums[i][1]=sums[i-1][1];
        }
        else{
            sums[i][0]=sums[i-1][0];
            sums[i][1]=sums[i-1][1]+arr[i];
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        long long int aux=0;
        long long int sumpar=0, sumimpar=0;

        if(i==0){
            sumimpar = sums[n-1][0]-sums[i][0];
            sumpar = sums[n-1][1];
        }
        else{
            sumimpar=sums[(i-1>0? i-1: 0)][0];
            sumimpar+=sums[n-1][1]-sums[i][1];
            sumpar=sums[i-1>0? i-1: 0][1];
            sumpar+=sums[n-1][0]-sums[i][0];
        }

        if(sumpar==sumimpar) res++;
        //cout<<i<<" "<<sumpar<<" "<<sumimpar<<endl;
    }
    cout<<res<<endl;
    return 0;
}