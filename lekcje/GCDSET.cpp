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
  ll n,m,x=1;
  cin >> n;
  m=n;
  vector<ll> divs;
  for(ll i = 2; i*i <= n; i++){
    while(m%i == 0){
      divs.pb(i);
      m /= i;
    }
  }
  if(m != 1) divs.pb(m);
  sort(divs.begin(), divs.end());
  for(ll i = 0; i < divs.size(); i++){
    if(i) x *= divs[i];
    else x *= divs[i]+1;
  }
  cout << x << endl;
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