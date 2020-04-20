#include <bits/stdc++.h>
using namespace std;
void solve(){
  int N; cin >> N;
  auto findBottom = [&]()->int{
    return min(29,N-1);
  };
  int r = findBottom();
  auto getRows = [&]()->set<int>{
    set<int> ret;
    N -= (r+1);
    for(int i=r; i>=0; i--){
      if((1<<i)-1 <= N){
        ret.insert(i);
        N-=((1<<i)-1);
      }
    }
    r += N;
    return ret;
  };
  set<int> rows = getRows();
  auto getPath = [&]()->vector<vector<int>>{
    vector<vector<int>> ret;
    char d = 'l';
    for(int i=0; i<=r; i++){
      if(rows.count(i)==0){
        if(d=='l') ret.push_back({i+1,1});
        else ret.push_back({i+1,i+1});
      }else{
        if(d=='l'){for(int j=0; j<=i; j++) ret.push_back({i+1,j+1}); d='r';}
        else{for(int j=i; j>=0; j--) ret.push_back({i+1,j+1}); d='l';}
      }
    }
    return ret;
  };
  vector<vector<int>> path = getPath();
  
  for(auto p : path){
    cout << p[0] << " " << p[1] << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  for(int i = 1; i<=t; i++){
    cout << "Case #" << i << ": " << endl;
    solve();
  } 

}
