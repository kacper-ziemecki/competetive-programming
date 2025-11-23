#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

void solve(){
  int n;
  cin >> n;
  vector<int> lista(n);
  for(auto &el : lista) cin >> el;
  if(n&1 && lista[0]&1 && lista[n-1]&1){
    cout << "Yes\n"; return;
  }
  for(int i = 0; i < n; i+=2){
    for(int j = i+1; j < n; j+=2){
      if(!((n-j-1)&1)) continue;
      if(lista[0]&1 && lista[i]&1 && lista[i+1]&1 && lista[j]&1 && lista[j+1]&1 && lista[n-1]&1){
        cout << "Yes\n"; return;
      }
    }
  }
  cout << "No\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("../../in.in", "r", stdin);
  // freopen("../../out.out", "w", stdout);

  solve();
}