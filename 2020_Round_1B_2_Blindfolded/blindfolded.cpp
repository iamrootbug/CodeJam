#include <bits/stdc++.h>
using namespace std;
int A,B;
void solve(){
  bool fin = false;
  auto query = [&](int x, int y)->string{
    cout << x << " " << y << endl;
    string res; cin >> res;
    if(res=="WRONG") exit(0);
    if(res=="CENTER") fin=true;
    return res;
  };
   
  auto inner = [&]()->pair<int,int>{
    int d = 1e9 / 4;
    int x, y;
    for(int i=-d*3; i<=d*3; i+=d){
      for(int j=-d*3; j<=d*3 && !fin; j+=d){
        string res = query(i,j);
        if(res == "HIT"){
          x = i; y = j;
          break;
        }
      }
    }
    return {x,y};
  };
  pair<int,int> in = inner();

  auto rightMost = [&](int x, int y)->pair<int,int>{
    int t = x;
    int f = 1e9+1;
    while(t+1<f && !fin){
      int m = (t+f)/2;
      string res = query(m,y);
      if(res == "HIT") t=m;
      if(res == "MISS") f=m;
    }
    return {t,y};
  };
  pair<int,int> p0 = rightMost(in.first,in.second);

  auto leftMost = [&](int x, int y)->pair<int,int>{
    int t = x;
    int f = -1e9-1;
    while(f<t-1 && !fin){
      int m = (t+f)/2;
      string res = query(m,y);
      if(res == "HIT") t=m;
      if(res == "MISS") f=m;
    }
    return {t,y};
  };
  pair<int,int> p1 = leftMost(in.first,in.second);

  auto upMost = [&](int x, int y)->pair<int,int>{
    int t = y;
    int f = 1e9+1;
    while(t+1<f && !fin){
      int m = (t+f)/2;
      string res = query(x,m);
      if(res == "HIT") t=m;
      if(res == "MISS") f=m;
    }
    return {x,t};
  };
  pair<int,int> p2 = upMost(in.first,in.second);
  
  auto downMost = [&](int x, int y)->pair<int,int>{
    int t = y;
    int f = -1e9-1;
    while(f<t-1 && !fin){
      int m = (t+f)/2;
      string res = query(x,m);
      if(res == "HIT") t=m;
      if(res == "MISS") f=m;
    }
    return {x,t};
  };
  pair<int,int> p3 = downMost(in.first,in.second);

  if(!fin){
    int x = (p0.first+p1.first)/2;
    int y = (p2.second+p3.second)/2;
    for(int i=-3; i<=3; i++){
      for(int j=-3; j<=3 && !fin; j++){
        if(x+i<-1e9 || x+i>1e9 || y+j<-1e9 || y+j>1e9) continue;
        string res = query(x+i,y+j);
      }
    }
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t = 1;
  cin >> t >> A >> B;
  cerr << t << " " << A << " " << B << endl;
  for(int i = 1; i<=t; i++){
    //cout << "Case #" << i << ": ";
    solve();
  } 
}
