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
  ld n,suma=0,mx=0;
  cin >> n;
  ld a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<ll> list(n);
  for(auto& el : list) cin >> el;
  for(auto el : list){
    suma += el;
    if(el > mx) mx = el;
  }
  ld dist = sqrt((c-a)*(c-a) + (d-b)*(d-b));
  // dbg(dist, suma);
  if(!(mx <= (suma-mx+dist))) cout << "NO\n";
  else if(n == 1 && suma != dist) cout << "NO\n";
  else if(suma < dist) cout << "NO\n";
  else{
    cout << "YES\n";
  }
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