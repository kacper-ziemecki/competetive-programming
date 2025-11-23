#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

void solve(){
  int n,k,res=0;
  cin >> n >> k;
  vector<int> lista(n);
  for(auto &el : lista) cin >> el;
  for(int i = 1; i < n; i++){
    res += max(0, k-(lista[i]+lista[i-1]));
    lista[i] += max(0, k-(lista[i]+lista[i-1]));
  }
  cout << res << endl;
  for(auto el : lista) cout << el << ' ';
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("../../in.in", "r", stdin);
  // freopen("../../out.out", "w", stdout);

  solve();
}