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
  ll n,q,a,l,d;
  cin >> n >> q;
  vector<ll> res(n+1);
  vector<vector<ll>> queries(q+1), actions(n+1), pierwiastek((ll)sqrt(n)+1, vector<ll>((ll)sqrt(n)+1, 0));
  for(ll i = 1; i <= q; i++){
    cin >> a >> l >> d;
    queries[i] = {a,l,d};
    actions[a].pb(i);
    if(d < sqrt(n) && a+l*d <= n) actions[a+l*d].pb(-i);
  }

  // cout << "actions: \n";
  // for(ll i = 0; i <= n; i++){
  //   cout << i << " -> ";
  //   for(auto el : actions[i]) cout << el << " ";
  //   cout << endl;
  // }

  for(ll i = 1; i <= n; i++){
    for(auto action : actions[i]){
      // dbg(action);
      if(action > 0 && queries[action][2] < sqrt(n)){
        // cout << "action > 0 : " << action << endl; 
        // dbg(queries[action][0], queries[action][1], queries[action][2], queries[action][0] % queries[action][2]);
        pierwiastek[queries[action][2]][queries[action][0] % queries[action][2]]++;
      }
      else if(action < 0){
        // cout << "action < 0 : " << action << endl;
        pierwiastek[queries[-action][2]][queries[-action][0] % queries[-action][2]]--;
      }
      else{
        // cout << "> sqrt(n) : " << action << endl;
        for(ll j = queries[action][0]; j < queries[action][0]+queries[action][1]*queries[action][2]; j += queries[action][2]){
          res[j]++;
        }
      }
    }
    for(ll j = 1; j < sqrt(n); j++){
      res[i] += pierwiastek[j][i%j]; 
    }
  }
  for(ll i = 1; i <= n; i++) cout << res[i] << " ";
  cout << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}