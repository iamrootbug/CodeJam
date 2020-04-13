#include <bits/stdc++.h>
using namespace std;
void solve(){
	int N; cin >> N;
	vector<vector<int>> m(N, vector<int>(N));
	for(int y=0; y<N; y++)
		for(int x=0; x<N; x++)
			cin >> m[y][x];
	int d(0), r(0), c(0);
	for(int i=0; i<N; i++)
		d+=m[i][i];
	for(int y=0; y<N; y++){
		vector<int> tt(N+1,0);
		for(int x=0; x<N; x++){
			if(tt[m[y][x]]>0){r++; break;}
			else tt[m[y][x]]++;
		}
	}
	for(int x=0; x<N; x++){
		vector<int> tt(N+1,0);
		for(int y=0; y<N; y++){
			if(tt[m[y][x]]>0){c++; break;}
			else tt[m[y][x]]++;
		}
	}
	cout << d << " " << r << " " << c << endl;
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
