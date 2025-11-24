#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  ll n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<ll> suffix(n,LLONG_MAX);
  ll prefix=LLONG_MAX;
  if(s[n-1] == '1') suffix[n-1]=0;
  for(ll i = n-2; i >= 0; i--){
    suffix[i] = suffix[i+1];
    if(suffix[i] != LLONG_MAX) suffix[i]++;
    if(s[i] == '1') suffix[i] = 0;
  }
  // for(auto el : suffix) cout << el << " ";
  // cout << endl;
  ll res=0;
  for(ll i = 0; i < n; i++){
    if(prefix != LLONG_MAX) prefix++;
    if(s[i] == '1') prefix=0;
    if(prefix > k && suffix[i] > k){
      res++;
      prefix=0;
      s[i] = '1';
    }
  }
  // cout << s << endl;
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