#include <bits/stdc++.h>
using namespace std;
void solve(){
  int R, C; cin >> R >> C;
  vector<vector<int>> m(R, vector<int>(C));
  for(int y=0; y<R; y++)
    for(int x=0; x<C; x++)
      cin >> m[y][x];
  vector<vector<int>> u,d,l,r;
  u = d = l = r = vector<vector<int>>(R,vector<int>(C));
  for(int y=0; y<R; y++)
    for(int x=0; x<C; x++){
      u[y][x] = y-1;
      d[y][x] = (y<R-1 ? y+1 : -1);
      l[y][x] = x-1;
      r[y][x] = (x<C-1 ? x+1 : -1);
    }
  
  auto check = [&](int y, int x)->bool{
    int sum, cnt;
    sum = cnt = 0;
    if(u[y][x] != -1){cnt++; sum+=m[u[y][x]][x];}
    if(d[y][x] != -1){cnt++; sum+=m[d[y][x]][x];}
    if(l[y][x] != -1){cnt++; sum+=m[y][l[y][x]];}
    if(r[y][x] != -1){cnt++; sum+=m[y][r[y][x]];}
    if(m[y][x]*cnt < sum) return true;
    else return false;
  };
  
  vector<vector<int>> willRemv;
  long long ans, cur;
  ans = cur = 0;
  for(int y=0; y<R; y++)
    for(int x=0; x<C; x++){
      cur += m[y][x];
      if(check(y,x)) willRemv.push_back({y,x});
    }
  vector<vector<bool>> deleted(R,vector<bool>(C,false));
  while(1){
    ans += cur;
    if(willRemv.empty()) break;
    vector<vector<int>> candi;
    for(auto n : willRemv){
      int y = n[0];
      int x = n[1];
      if(u[y][x] != -1){candi.push_back({u[y][x],x});}
      if(d[y][x] != -1){candi.push_back({d[y][x],x});}
      if(l[y][x] != -1){candi.push_back({y,l[y][x]});}
      if(r[y][x] != -1){candi.push_back({y,r[y][x]});}
    }
    for(auto n : willRemv){
      int y = n[0];
      int x = n[1];
      if(deleted[y][x]) continue;
      cur -= m[y][x];
      deleted[y][x] = true;
      if(u[y][x] != -1){d[u[y][x]][x] = d[y][x];}
      if(d[y][x] != -1){u[d[y][x]][x] = u[y][x];}
      if(l[y][x] != -1){r[y][l[y][x]] = r[y][x];}
      if(r[y][x] != -1){l[y][r[y][x]] = l[y][x];}
    }
    willRemv.clear();
    for(auto n : candi){
      int y = n[0];
      int x = n[1];
      if(deleted[y][x]) continue;
      if(check(y,x)) willRemv.push_back({y,x});
    }
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  for(int i = 1; i<=t; i++){
    cout << "Case #" << i << ": ";
    solve();
  } 
}
