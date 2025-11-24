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




void solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n);
  unordered_map<ll,ll> count;
  for(auto &el : list) cin >> el;
  for(auto el : list) count[el%k]++;
  ll suma = 0,mn;
  for(auto el : list) suma += el;
  dbg(suma);
  for(ll i = 0; i < 1; i++){
    for(auto [j, x] : count){
      if(i-j != j && count.count(i-j)){
        mn = min(count[j], count[i-j]);
        suma -= mn*i;
        count[j] -= mn; count[i-j] -= mn;
        // if(count[i-j] == 0) count.erase(i-j);
      }
      if(i-j == j && count.count(i-j)){
        mn = count[j]/2;
        suma -= mn*i;
        count[j] -= 2*mn;
      }
      if(k-j+i != j && count.count(k-j+i)){
        mn = min(count[j], count[k-j+i]);
        suma -= mn*i;
        count[j] -= mn; count[k-j+i] -= mn;
        // if(count[k-j+i] == 0) count.erase(k-j+i);
      }
      if(k-j+i == j && count.count(k-j+i)){
        mn = count[j]/2;
        suma -= mn*i;
        count[j] -= 2*mn;
      }
      for(auto el : count) cout << el.first << "->" << el.second << endl;
      cout << endl;
      // dbg(j,i,suma);
      if(count[j] == 0) count.erase(j);
    }
    // dbg(suma);
  }
  cout << suma/k << endl;
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