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

ll n,k,m,l;


void solve()
{
  cin >> n >> k >> m;
  ll l = ceil(log2(m));
  vector<vector<ll>> up(n, vector<ll>(l+1, -1));
  vector<ll> list(n), connections(n);
  for(auto &el : list) cin >> el;

  ll left = 0, right = k;
  for(ll i = 0; i < n; i++){
    while(right+1 < n && abs(list[right+1] - list[i]) < abs(list[left] - list[i])){
      left++;
      right++;
    }

    if(abs(list[right]-list[i]) > abs(list[left]-list[i])){
      connections[i] = right;
    } else{
      connections[i] = left;
    }
  }


  // cout << "connections:\n";
  // for(auto el : connections) cout << el << " ";
  // cout << endl;

  for(ll i = 0; i <= l; i++){
    for(ll j = 0; j < n; j++){
      up[j][i] = (i ? up[up[j][i-1]][i-1] : connections[j]);
    }
  }

  // cout << "up:\n";
  // for(ll i = 0; i < n; i++){
  //   cout << i << " : ";
  //   for(ll j = 0; j <= l; j++) cout << up[i][j] << " ";
  //   cout << endl;
  // }
  for(ll i = 0; i < n; i++){
    ll steps = 0;
    ll node = i;
    for(ll j = l; j >= 0; j--){
      // dbg(node, j);
      if(steps+pow(2,j) <= m){
        // dbg(node, j, up[node][j]);
        node = up[node][j];
        steps += pow(2,j);
      }
    }
    // dbg(node);
    cout << node+1 << " ";
  }
  cout << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}