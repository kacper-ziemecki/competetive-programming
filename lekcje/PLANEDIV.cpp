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
  ll n;
  cin >> n;
  map<pair<ll,ll>,set<pair<ll,ll>>> mp;
  ll a,b,c;
  for(ll i = 0; i < n; i++){
    cin >> a >> b >> c;
    if(a == 0){
      mp[{0,1}].emplace(c/__gcd(c,b), b/__gcd(c,b));
    } else if(b == 0){
      mp[{1,0}].emplace(c/__gcd(c,a), a/__gcd(c,a));
    }
    else mp[{a/__gcd(a,b), b/__gcd(a,b)}].emplace(c/__gcd(c,b), b/__gcd(c,b));
  }
  ll res = 1;
  for(auto el : mp){
    res = max(res, (ll)el.second.size());
    // dbg(el.first.first, el.first.second);
    // for(auto el1 : el.second){
    //   dbg(el1);
    // }
  }
  cout << res << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;
  while(t--)
  solve();
}