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
  vector<ll> res(6, 0),numbers = {4,8,15,16,23,42};
  vector<unordered_map<ll,ll>> cnt(6);
  unordered_map<ll,bool> mp,vis;
  for(auto el : numbers) mp[el]=true;
  ll x;
  for(ll i = 1; i < 5; i++){
    cout << "? " << i << " " << i+1 << endl;
    cin >> x;
    for(auto el : numbers){
      if(x % el == 0 && mp.count(x/el) && x/el != el){
        cnt[i-1][el]++;
        cnt[i][x/el]++;
      }
    }
    // for(auto sub : cnt){
    //   for(auto [a,b] : sub){
    //     cout << a << "->" << b << ", ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
  }
  for(ll i = 1; i < 4; i++){
    for(auto [a,b] : cnt[i]){
      if(b == 2){
        res[i] = a;
        vis[a] = true;
      }
    }
  }
  for(auto [a,b] : cnt[0]){
    if(!vis[a]){
      res[0] = a;
      vis[a] = true;
    }
  }
  for(auto [a,b] : cnt[4]){
    if(!vis[a]){
      res[4] = a;
      vis[a] = true;
    }
  }
  for(auto el : numbers){
    if(!vis[el]){
      res[5] = el;
      vis[el] = true;
    }
  }
  cout << "!";
  for(auto el : res) cout << " " << el;
  cout << endl;
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  solve();
}