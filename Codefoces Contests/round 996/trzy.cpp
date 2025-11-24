#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll n,m;
  string s;
  cin >> n >> m >> s;
  vector<vector<ll>> list(n, vector<ll>(m));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      cin >> list[i][j];
    }
  }

  vector<ll> rows(n),columns(m);
  for(ll i = 0; i < n; i++){
    ll tmp=0;
    for(ll j = 0; j < m; j++){
      tmp += list[i][j];
    }
    rows[i]=tmp;
  }
  for(ll j = 0; j < m; j++){
    ll tmp=0;
    for(ll i = 0; i < n; i++){
      tmp += list[i][j];
    }
    columns[j]=tmp;
  }

  ll i=0,j=0;
  pair<ll, ll> res{0,0};
  for(ll k = 0; k < s.size(); k++){
    if(k > 0 && s[k] != s[k-1]){
      if(s[k] == 'R'){
        res = {1 - res.first, -res.second - columns[j]};
      } else{
        res = {1 - res.first, -res.second - rows[i]};
      }
    } else{
      if(s[k] == 'R'){
        res = {res.first+1, res.second-columns[j]};
      } else{
        res = {res.first+1, res.second-rows[i]};
      }
    }
    if(s[k] == 'R') j++;
    else i++;
    dbg(res.first, res.second);
  }
  if(s[s.size()-1] == s[s.size()-2]){
    if(s[s.size()-1] == 'R'){
        res = {res.first+1, res.second-columns[j]};
      } else{
        res = {res.first+1, res.second-rows[i]};
      }
  } else{
    if(s[s.size()-1] == 'R'){
        res = {1 - res.first, -res.second - columns[j]};
      } else{
        res = {1 - res.first, -res.second - rows[i]};
      }
  }
  dbg(res.first, res.second);
}
int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--)
  solve();
}