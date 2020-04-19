#include <bits/stdc++.h>
using namespace std;
int B;
void solve(){
  auto query = [](int i)->int{
    int ret;
    cout << i+1 << endl;
    cin >> ret;
    return ret;
  };
  vector<int> ans(B,-1);
  int L=0, R=B;
  while(L<R){
    int iter = 10;
    for(int i=0; i<L; i++){
      if(ans[i] == ans[B-1-i]){
        iter--;
        if(query(i) != ans[i]){
          //complement
          for(int j=0; j<B; j++){
            if(ans[j]!=-1) ans[j]^=1;
          }
        }
        break;
      }
    }
    for(int i=0; i<L; i++){
      if(ans[i] != ans[B-1-i]){
        iter--;
        if(query(i) != ans[i]){
          //reverse
          reverse(ans.begin(),ans.end());
        }
        break;
      }
    }
    while(iter>=2 && L<R){
      if(L<R){ ans[L] = query(L); L++; iter--;}
      if(L<R){ --R; ans[R] = query(R); iter--;}
    }
    if(iter>0) query(0);
  }
  for(auto& i : ans) cout << i;
  cout << endl;
  string result;
  cin >> result;
  if(result == "N"){
    cerr << "ERROR" << endl;
  }else{
    cerr << "DONE" << endl;
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t = 1;
  cin >> t >> B;
  cerr << t << " " << B << endl;
  for(int i = 1; i<=t; i++){
    //cout << "Case #" << i << ": ";
    solve();
  } 
}
