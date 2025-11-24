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
  set<pair<ll,ll>> res;
  queue<pair<ll,ll>> q;
  vector<ll> vis(n+1, LLONG_MAX);

  for(ll i = 2; i <= n; i++){
    q.emplace(make_pair(1, i));
    while(!q.empty()){
      pair<ll,ll> edge = q.front(); q.pop();
      vis[edge.first] = min(i, vis[edge.first]); vis[edge.second] = min(i, vis[edge.second]);
      if(vis[edge.first] < i && vis[edge.second] < i) continue;
      cout << "? " << edge.first << " " << edge.second << endl;
      cin >> x;
      if(x == -1) return;
      if(x == edge.first) res.emplace(min(edge.first,edge.second),max(edge.first,edge.second));
      else{
        // cout << "x: " << x << "  dodajemy: ";
        // dbg(x, edge.second);
        // dbg(edge.first, x);
        q.emplace(make_pair(x, edge.second));
        q.emplace(make_pair(edge.first, x));
      }
    }
  }
  cout << "! ";
  for(auto edge : res){
    cout << edge.first << " " << edge.second << " "; 
  }
  cout << endl;
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