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
  ll n,q,res=1;
  cin >> n >> q;
  char a;
  string s;
  cin >> s;
  vector<ll> list(n+q);
  list[0] = 1;
  for(ll i = 1; i < n; i++){
    if(s[i] == s[i-1]) list[i] = list[i-1]+1;
    else list[i] = 1;
    res = max(res, list[i]);
  }
  cout << res << " ";
  for(ll i = n; i < n+q; i++){
    cin >> a;
    if(a == s.back()) list[i] = list[i-1]+1;
    else list[i] = 1;
    res = max(res, list[i]);
    s += a;
    cout << res << " ";
  }
  cout << endl;
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