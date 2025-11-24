#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve()
{
  ll n,x;
  cin >> n;
  vector<ll> list(n);
  vector<bool> vis(n+1);
  for(auto &el : list) cin >> el;
  for(auto el : list) vis[el]=true;
  bool flag = false;
  for(ll i = 1; i <= n; i++) if(!vis[i]) flag = true;
  if(flag){
    for(ll i = 1; i <= n; i++){
      if(vis[i]){
        for(ll j = 1; j <= n; j++){
          if(j==i || vis[j]) continue;
          cout << "? " << j << " " << i << endl;
          cin >> x;
          if(x) cout << "! B" << endl;
          else cout << "! A" << endl;
          return;
        }
      }
    }
  } else{
    ll one,two;
    for(ll i = 0; i < n; i++){
      if(list[i] == 1) one = i+1;
      if(list[i] == n) two = i+1;
    }
    cout << "? " << one << " " << two << endl;
    cin >> x;
    if(x < n-1){ cout << "! A" << endl; return; }
    cout << "? " << two  << " " << one << endl;
    cin >> x;
    if(x < n-1){ cout << "! A" << endl; return; }
    cout << "! B" << endl;
  }
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  ll t;
  cin >> t;
  while(t--)
  solve();
}