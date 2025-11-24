#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll a,b,k,res=0;
  cin >> a >> b >> k;
  vector<pair<ll,ll>>list(k);
  vector<ll> list1(k);
  for(auto &el : list) cin >> el.first;
  for(auto &el : list) cin >> el.second;
  sort(list.begin(), list.end());
  for(ll i = 0; i < k; i++) list1[i] = list[i].first;
  map<ll, vector<ll>> mp;
  for(ll i = 0; i < k; i++) mp[list[i].second].push_back(i);
  for(auto &el : mp) sort(el.second.begin(), el.second.end());
  // for(auto el : list1) cout << el << " ";
  // cout << endl;
  for(ll i = 0; i < k; i++){
    ll j1 = upper_bound(list1.begin(), list1.end(), list1[i])-list1.begin();
    // dbg(i, list1[i], j1);
    ll j2 = lower_bound(mp[list[i].second].begin(), mp[list[i].second].end(), j1)-mp[list[i].second].begin();
    // for(auto el : mp[list[i].second]) cout << el << " ";
    // cout << endl;
    // dbg(j2, mp[list[i].second].size()-j2);
    res += (k-j1)-(mp[list[i].second].size()-j2);
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