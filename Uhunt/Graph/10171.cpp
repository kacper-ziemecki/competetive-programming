#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(ll n){
  vector<vector<ll>> amy(2*n, vector<ll>(2*n, LLONG_MAX)), amm(2*n, vector<ll>(2*n, LLONG_MAX));
  for(ll i = 0; i < 2*n; i++){
    amy[i][i] = 0;
    amm[i][i] = 0;
  }
  map<char, ll> mp;
  map<ll, char> reverseMp;
  ll cnt=0;
  char a,b,c,d;
  ll w;
  for(ll i = 0; i < n; i++){
    cin >> a >> b >> c >> d >> w;
    if(mp.count(c) == 0){ reverseMp[cnt] = c; mp[c] = cnt++; }
    if(mp.count(d) == 0){ reverseMp[cnt] = d; mp[d] = cnt++; }
    if(a == 'Y'){
      amy[mp[c]][mp[d]] = min(amy[mp[c]][mp[d]],w);
      if(b == 'B') amy[mp[d]][mp[c]] = min(amy[mp[d]][mp[c]],w);
    } else{
      amm[mp[c]][mp[d]] = min(amm[mp[c]][mp[d]],w);
      if(b == 'B') amm[mp[d]][mp[c]] = min(amm[mp[d]][mp[c]],w);
    }
  }

  for(ll k = 0; k < 2*n; k++){
    for(ll i = 0; i < 2*n; i++){
      for(ll j = 0; j < 2*n; j++){
        if(amy[i][k]==LLONG_MAX||amy[k][j]==LLONG_MAX) continue;
        amy[i][j] = min(amy[i][j], amy[i][k]+amy[k][j]);
      }
    }
  }
  for(ll k = 0; k < 2*n; k++){
    for(ll i = 0; i < 2*n; i++){
      for(ll j = 0; j < 2*n; j++){
        if(amm[i][k]==LLONG_MAX||amm[k][j]==LLONG_MAX) continue;
        amm[i][j] = min(amm[i][j], amm[i][k]+amm[k][j]);
      }
    }
  }
  cin >> a >> b;
  ll res = LLONG_MAX;
  vector<ll> ans;
  for(ll i = 0; i < 2*n; i++){
    if(amy[mp[a]][i]==LLONG_MAX||amm[mp[b]][i]==LLONG_MAX) continue;
    if(res == amy[mp[a]][i]+amm[mp[b]][i]){
      ans.push_back(i);
    } else if(res > amy[mp[a]][i]+amm[mp[b]][i]){
      ans = {i};
      res = amy[mp[a]][i]+amm[mp[b]][i];
    }
  }
  if(res == LLONG_MAX){
    cout << "You will never meet.\n";
  } else{
    cout << res << " ";
    for(ll i = 0; i < ans.size(); i++){
      if(i!=0) cout << " ";
      cout << reverseMp[ans[i]];
    }
    cout << endl;
  }
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
  
  ll n;
  while(cin >> n, n != 0) solve(n);
}