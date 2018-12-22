#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;

int n, q, dist[5010][5010], vis[5010][5010];

int main(){
  cin >> n >> q;
  queue<pii> qu;
  int x, y;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    qu.push({x, y});
    vis[x][y] = 1;
  }
  while(!qu.empty()){
    int xc = qu.front().fi;
    int yc = qu.front().se;
    qu.pop();
    // cout << qu.size() << endl;;
    // cout << xc << ' ' << yc << endl;
    for(int i = -1; i <= 1; i++){
      for(int j = -1; j <= 1; j++){
      	//if(i * i + j * j != 1) continue;
      	int vx = xc + i, vy = yc + j;
      	if(vx < 0 || vx > 5005 || vy < 0 || vy > 5005) continue;
      	if(vis[vx][vy]) continue;
      	//cout << vx << ' ' << vy << endl;
      	vis[vx][vy] = 1;
      	dist[vx][vy] = dist[xc][yc] + 1;
      	qu.push({vx, vy});
      }
    }
  }
  int a, b;
  while(q--){
    cin >> a >> b;
    cout << dist[a][b] << endl;
  }
}
