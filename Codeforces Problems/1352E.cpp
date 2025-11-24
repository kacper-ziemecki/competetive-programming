#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n), prefix(n, 0);
  for(auto &el : list) cin >> el;
  prefix[0]=list[0];
  for(ll i = 1; i < n; i++) prefix[i]=prefix[i-1]+list[i];
  vector<bool> res(n, false), mp(n*n+1, false);
  for(ll i = 0; i < n; i++){ // indeks prefiksowy
    for(ll j = 0; j < n; j++){ // indeks listy
      if((prefix[i]-list[j] >= 0 && mp[prefix[i]-list[j]]) || (i > 0 && prefix[i] == list[j])){
        res[j]=true;
        // dbg(j, i);
      }
    }
    if(i>0) mp[prefix[i-1]]=true;
  }
  ll ans=0;
  for(auto el : res) if(el) ans++;
  cout << ans << endl;
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