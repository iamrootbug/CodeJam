#include <bits/stdc++.h>
using namespace std;
void solve(){
  int N; cin >> N;
  vector<string> in(N);
  for(int i=0; i<N; i++) cin >> in[i];

  string prefix(""), suffix("");
  vector<pair<int,int>> mid(N);
  bool ret = true;
  
  for(int i=0; i<N; i++){
    int j(0);
    for(j=0; j<(int)in[i].size(); j++){
      if(in[i][j]=='*') break;  
      if(j==(int)prefix.size()) prefix.push_back(in[i][j]);
      else if(prefix[j] != in[i][j]) ret=false;
    }
    mid[i].first = j;
    for(j=0; j<(int)in[i].size(); j++){
      if(in[i][in[i].size()-1-j]=='*') break;  
      if(j==(int)suffix.size()) suffix.push_back(in[i][in[i].size()-1-j]);
      else if(suffix[j] != in[i][in[i].size()-1-j]) ret=false;
    }
    mid[i].second = in[i].size()-j-1;
  }

  if(!ret){
    cout << "*" << endl;
    return;
  }else{
    cout << prefix;
    for(int i=0; i<N; i++){
      for(int j=mid[i].first+1; j<mid[i].second; j++){
        if(in[i][j] == '*') continue;
        cout << in[i][j];
      }
    }
    reverse(suffix.begin(), suffix.end());
    cout << suffix << endl;
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
