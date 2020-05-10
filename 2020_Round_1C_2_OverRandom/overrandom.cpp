#include <bits/stdc++.h>
using namespace std;
void solve(){
  int U; cin >> U;
  set<char> s;
  map<char,int> m;
  long long q; string str;
  for(int i=0; i<10000; i++){
    cin >> q >> str;
    for(auto& c : str) s.insert(c);
    m[str[0]]++;
  }
  vector<pair<char,int>> v(m.begin(), m.end());
  sort(v.begin(), v.end(), [](const pair<char,int>& l, const pair<char,int>& r){return l.second > r.second;});
  string ans;
  for(auto& it : v) ans.push_back(it.first);
  for(auto& it : ans) s.erase(it);
  ans.insert(ans.begin(), *s.begin());
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  for(int i = 1; i<=t; i++){
    cout << "Case #" << i << ": ";
    solve();
  } 
}
