//  Copyright © 2018 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long i64;

int N, ans, tot;
bool a[MAX];
int dpl[MAX];
int dpr[MAX];

int main()
{
    optimiza_io
    cin >> N;
    for( int i = 1; i <= N; i ++ )
    {
        char x;
        cin >> x;
        if( x == 'G' )
        {
            a[i] = 1;
            tot++;
        }
    }
    for( int i = 1; i <= N; i ++ )
        if( a[i] )
        {
            dpl[i] = 1 + dpl[i - 1];
            ans = max( ans , dpl[i] );
        }
    
    for( int i = N; i >= 1; i -- )
        if( a[i] )
        {
            dpr[i] = 1 + dpr[i + 1];
            ans = max( ans , dpr[i] );
        }
    
    for( int i = 1; i <= N; i ++ )
        if( ! a[i] && dpl[i - 1] + dpr[i + 1] != tot )
            ans = max( ans , 1 + dpl[i - 1 ] + dpr[i + 1] );
    
    for( int i = 1; i <= N; i ++ )
        if( ! a[i] )
            ans = max( ans , dpl[i - 1] + dpr[i + 1] );
    
    
    cout << ans;
    return 0;
}

/*
 
 9
 SGGGGSGGG
 
 */