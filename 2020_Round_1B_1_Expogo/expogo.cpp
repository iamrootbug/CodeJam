#include <bits/stdc++.h>
using namespace std;
void solve(){
  int X, Y; cin >> X >> Y;
  int maxd = 0; int s = abs(X)+abs(Y);
  while((1<<maxd)-1<s) maxd++;
  function<string(int,int,int)> sub = [&](int x, int y, int d)->string{
    if(x==0 && y==0) return "";
    //if(((x+y)%2+2)%2 == 0) return "IMPOSSIBLE";
    if((abs(x)%2+abs(y)%2)%2 == 0) return "IMPOSSIBLE";
    if(d >= 50) return "IMPOSSIBLE";
    
    if(abs(x)%2 == 1){
      vector<pair<int,string>> candi = {{(x-1)/2,"E"}, {(x+1)/2,"W"}};
      for(auto& c : candi){
        if(c.first==0 && y/2==0) return c.second;  
      }
      string res = "IMPOSSIBLE";
      for(auto& c : candi){
        res = sub(c.first, y/2, d+1);
        if(res != "IMPOSSIBLE") return c.second + res;
      }
      return res;
    }
    if(abs(y)%2 == 1){
      vector<pair<int,string>> candi = {{(y-1)/2,"N"}, {(y+1)/2,"S"}};
      for(auto& c : candi){
        if(x/2==0 && c.first==0) return c.second;  
      }
      string res = "IMPOSSIBLE";
      for(auto& c : candi){
        res = sub(x/2, c.first, d+1);
        if(res != "IMPOSSIBLE") return c.second + res;
      }
      return res;
    }
    return "IMPOSSIBLE";
  };
  cout << sub(X,Y,0) << endl;
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
