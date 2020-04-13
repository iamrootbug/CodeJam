#include <bits/stdc++.h>
using namespace std;
void solve(){
  int N; cin >> N;
  vector<vector<int>> sch(N, vector<int>(3));
  for(int i=0; i<N; i++){
    cin >> sch[i][0] >> sch[i][1];
    sch[i][2] = i;
  }
  vector<char> who(N);
  
  sort(sch.begin(), sch.end());
  int juntil = -1;
  int cuntil = -1;
  for(int i=0; i<N; i++){
    if(juntil <= sch[i][0]){
      who[sch[i][2]] = 'J';
      juntil = sch[i][1];
    }else if(cuntil <= sch[i][0]){
      who[sch[i][2]] = 'C';
      cuntil = sch[i][1];
    }else{
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }
  for(int i=0; i<N; i++) cout << who[i];
  cout << endl;
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
