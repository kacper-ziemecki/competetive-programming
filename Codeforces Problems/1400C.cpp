#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  string s;
  ll k,n;
  cin >> s >> k;
  n = s.size();
  string w(n, '-');
  for(ll i = 0; i < n; i++){
    if(s[i] == '0'){
      if(i-k >= 0){
        if(w[i-k] == '1'){ cout << -1 << endl; return; }
        w[i-k] = '0';
      }
      if(i+k < n){
        if(w[i+k] == '1'){ cout << -1 << endl; return; }
        w[i+k] = '0';
      }
    }
    else{
      ll cnt=0;
      if(i-k >= 0 && w[i-k] != '0'){ w[i-k] = '1'; cnt++; }
      if(i+k < n && w[i+k] != '0' && cnt == 0){ w[i+k] = '1'; cnt++; }
      if(!cnt){ cout << -1 << endl; return; }
    }
    // dbg(i, w);
  }
  for(auto &el : w) if(el == '-') el = '0';
  cout << w << endl;
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