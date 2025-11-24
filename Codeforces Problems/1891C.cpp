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
  ll n;
  cin >> n;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());
  for(auto el : list) cout << el << " ";
  cout << endl;
  ll right = n-1, sum = 0, res = 0;
  for(ll left = 0; left < right; left++){
    ll list_left = list[left];
    list[left] -= min(list[right]-sum, list[left]);
    sum += min(list[right]-sum, list_left);
    for(auto el : list) cout << el << " ";
    cout << endl;
    dbg(left,sum,res,right,list[left]);
    if(sum == list[right]){
      res += sum+1;
      list[right] = 0;
      right--;
      sum += list[left];
      list[left] = 0;
    }
  }
  if(list[right]){
    ll calkowite = (sum + list[right])/2;
    res += calkowite + 1 + (list[right]&1);
  } else if(sum){
    ll calkowite = sum/2;
    res += calkowite + 1 + (sum&1);
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