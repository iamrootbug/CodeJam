#include <bits/stdc++.h>
using namespace std;
void solve(){
  int R, S; cin >> R >> S;
  
  vector<int> d;
  for(int i=0; i<S; i++)
    for(int j=0; j<R; j++)
      d.push_back(j+1); // 1,2,3,..R,1,2,3,...R
  
  int ans = (R*(S-1))/2;
  //if(R*(S-1)%2 == 1) ans++;
  vector<pair<int,int>> ansv;
  for(int round=0; round<ans; round++){
    int i=0; while(d[i+1] == d[i]) i++;
    int j=i+1; while(d[j+1] == d[j]) j++;
    int l=j+1; while(d[l] != d[j]) l++;
    int k=l-1;
    ansv.push_back(make_pair(j+1,k-j));
    vector<int> tmp(d.begin()+j+1, d.begin()+l);
    tmp.insert(tmp.end(), d.begin(), d.begin()+j+1);
    tmp.insert(tmp.end(), d.begin()+l, d.end());
    d = tmp;
  }
  if(R*(S-1)%2 == 1){
    ans++;
    ansv.push_back(make_pair(S-1,S*(R-1)));
  }
  cout << ans << endl;
  for(auto& it : ansv){
    cout << it.first << " " << it.second << endl;
  }
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
