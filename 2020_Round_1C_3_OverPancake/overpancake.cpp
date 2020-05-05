#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
  int N, D; cin >> N >> D;
  vector<ll> A(N);
  for(int i=0; i<N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  map<pair<ll,ll>, int> M0;
  map<pair<ll,ll>, int> M1;
  for(int i=0; i<N; i++){
    for(int c=1; c<=D; c++){
      ll g = __gcd(A[i],(ll)c);
      ll a = A[i]/g;
      ll b = (ll)c/g;
      if(M1[make_pair(a,b)] + c <= D){
        M0[make_pair(a,b)]++;
        M1[make_pair(a,b)]+=c;
      }
    }
  }
  int maxy = 0;
  auto exceed = [&](ll a, ll b)->bool{
    ll s = 0;
    for(int i=N-1; i>=0; i--){
      s += A[i]*b/a;
      if(s >= D) return true;
    }
    return false;
  };
  for(auto& it : M0){
    if(exceed(it.first.first ,it.first.second))
      maxy = max(maxy, it.second);
  }
  cout << D-maxy << endl; 
  return;
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
