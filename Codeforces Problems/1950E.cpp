#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


vector<ll> divisors(ll n){
  vector<ll> res;
  for(ll i = 1; i*i <= n; i++){
    if(n%i==0) res.pb(i);
    if(n%i==0 && (n/i) != i) res.pb(n/i);
  }
  return res;
}

bool helper(string& s, ll x){
  string a = s.substr(0,x)+'$'+s, b = s.substr(s.size()-x, x)+'$'+s;
  // dbg(a,b);
  ll n = a.size();
  vector<ll> z_function_a(n, 0),z_function_b(n, 0);
  for(ll i = 1; i < n; i++){
    ll j = z_function_a[i-1];
    while(j > 0 && a[j] != a[i]) j = z_function_a[j-1];
    if(a[j] == a[i]) j++;
    z_function_a[i] = j;
  }
  for(ll i = 1; i < n; i++){
    ll j = z_function_b[i-1];
    while(j > 0 && b[j] != b[i]) j = z_function_b[j-1];
    if(b[j] == b[i]) j++;
    z_function_b[i] = j;
  }
  vector<bool> vis_a((n-1-x)/x), vis_b((n-1-x)/x);
  // for(auto el : z_function_a) cout << el << " ";
  // cout << endl;
  // for(auto el : z_function_b) cout << el << " ";
  // cout << endl;
  for(ll i = 2*x; i < n; i+=x){
    vis_a[(i-2*x)/x] = z_function_a[i] == x;
    vis_b[(i-2*x)/x] = z_function_b[i] == x;
  }
  ll cnt_a = 0, cnt_b = 0;
  for(auto el : vis_a) if(!el) cnt_a++;
  for(auto el : vis_b) if(!el) cnt_b++;
  if(!cnt_a || !cnt_b) return true;
  
  // for(auto el : vis_a) cout << el << " ";
  // cout << endl;
  // for(auto el : vis_b) cout << el << " ";
  // cout << endl;
  if(cnt_a == 1){
    ll idx = 0;
    for(ll i = 0; i < vis_a.size(); i++){
      if(!vis_a[i]) idx = i;
    }
    ll cnt = 0;
    for(ll i = 0; i < x; i++){
      if(a[i] != a[i+x+(idx*x)+1]) cnt++;
    }
    if(cnt == 1) return true;
  } 
  if(cnt_b == 1){
    ll idx = 0;
    for(ll i = 0; i < vis_b.size(); i++){
      if(!vis_b[i]) idx = i;
    }
    ll cnt = 0;
    for(ll i = 0; i < x; i++){
      if(b[i] != b[i+x+(idx*x)+1]) cnt++;
    }
    if(cnt == 1) return true;
  }
  return false;
}

void solve()
{
  ll n,res=LLONG_MAX;
  string s;
  cin >> n >> s;
  vector<ll> divs = divisors(n);
  for(auto el : divs){
    if(helper(s, el)){
      // cout << "dziala " << el << endl;
      res = min(res, el);
    }
  }
  cout << res << endl;
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