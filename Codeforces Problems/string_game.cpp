#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool check(string& a, string& b, map<ll,ll>& mp, ll m, ll n){
  string a1;
  for(ll i = 0; i < n; i++){
    if(mp[i+1] < m) continue;
    a1 += a[i];
  }
  ll j = 0;
  for(ll i = 0; i < a1.size(); i++){
    if(j < b.size() && b[j] == a1[i]) j++;
  }
  return j==b.size();
}

void solve()
{
  string a,b;
  cin >> a >> b;
  ll n = a.size();
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  map<ll,ll> mp;
  for(ll i = 0; i < n; i++) mp[list[i]] = i;
  ll l=0,r=n;
  while(l<r){
    ll m=(l+r+1)/2;
    if(check(a,b,mp,m,n)) l = m;
    else r = m-1;
  }
  cout << l << endl;
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

  solve();
}