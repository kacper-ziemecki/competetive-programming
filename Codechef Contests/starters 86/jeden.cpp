#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 



void solve(){
  int n,res=0;
  cin >> n;
  vector<int> lista(n, 0);
  for(auto &el : lista) cin >> el;
  for(int i = 0; i < n; i++){
    if(i == 0){
      res = abs(lista[i] - lista[i+1]);
    }
    else if(i == n-1){
      res = min(res, abs(lista[i] - lista[i-1]));
    }
    else{
      res = min(res, max(abs(lista[i] - lista[i-1]), abs(lista[i] - lista[i+1])));
    }
  }
  cout << res << endl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}