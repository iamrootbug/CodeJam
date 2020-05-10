#include <bits/stdc++.h>
using namespace std;
void solve(){
  int X, Y;
  string M;
  cin >> X >> Y >> M;
  vector<int> d(M.size()+1);
  vector<int> c(M.size()+1);
  d[0] = abs(X)+abs(Y);
  c[0] = 0;
  for(int i=1; i<=(int)M.size(); i++){
    c[i] = i;
    if(M[i-1]=='N') Y++;
    else if(M[i-1]=='S') Y--;
    else if(M[i-1]=='E') X++;
    else if(M[i-1]=='W') X--;
    d[i] = abs(X)+abs(Y);
  }
  int ans = -1;
  for(int i=0; i<=(int)M.size(); i++){
    if(c[i]>=d[i]){ans=c[i]; break;}
  }
  if(ans != -1) cout << ans << endl;
  else cout << "IMPOSSIBLE" << endl;
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
