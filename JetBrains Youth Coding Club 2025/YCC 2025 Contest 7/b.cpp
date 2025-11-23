#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

void solve(){
  ll a,b;
  cin >> a >> b;
  ll res = 1;
  for(ll i = b; i > a; i--){
    res *= i;
    res %= 10;
    if(res % 10 == 0){
      cout << 0 << endl;
      return;
    }
  }
  
  cout << res % 10 << endl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("../../in.in", "r", stdin);
  // freopen("../../out.out", "w", stdout);

  solve();
}