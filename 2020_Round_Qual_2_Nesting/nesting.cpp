#include <bits/stdc++.h>
using namespace std;
void solve(){
  string s; cin >> s;
  string a = "";
  int fir = s[0]-'0';
  int last = s[s.size()-1]-'0';
  for(int i=0; i<fir; i++) a.push_back('(');
  for(int i=0; i<(int)s.size()-1; i++){
    a.push_back(s[i]);
    if(s[i]<s[i+1]){
      int c = s[i+1]-s[i];
      for(int j=0; j<c; j++) a.push_back('(');
    }
    else if(s[i]>s[i+1]){
      int c = s[i]-s[i+1];
      for(int j=0; j<c; j++) a.push_back(')');
    }
  }
  a.push_back(s[s.size()-1]);
  for(int i=0; i<last; i++) a.push_back(')');
  
  cout << a << endl;
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
