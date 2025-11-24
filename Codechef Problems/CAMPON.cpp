#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll d;
  cin >> d;
  ll pi,di;
  vector<ll> list(32, 0), prefixList(32, 0);
  for(ll i = 0; i < d; i++){
    cin >> di >> pi;
    list[di] += pi;
  }
  for(ll i = 1; i < 32; i++) prefixList[i] = prefixList[i-1]+list[i];

  ll q;
  cin >> q;
  ll deadi,regi;
  for(ll i = 0; i < q; i++){
    cin >> deadi >> regi;
    if(prefixList[deadi] >= regi){
      cout << "Go Camp\n";
    } else{
      cout << "Go Sleep\n";
    }
  }
} 
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif


  ll t;
  cin >> t;
  while(t--)
  solve();
  
  
}