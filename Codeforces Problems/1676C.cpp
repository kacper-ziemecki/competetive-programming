#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


ll comp(string a, string b){
  ll ans=0;
  for(ll i = 0; i < a.size(); i++){
    ans += (max(a[i]-'0', b[i]-'0')-min(a[i]-'0', b[i]-'0'));
  }
  return ans;
}

void solve()
{
  ll n,m,res=LLONG_MAX;
  cin >> n >> m;
  vector<string> l(n, " ");
  for(auto &el : l) cin >> el;
  for(ll i = 0; i < n; i++){
    for(ll j = i+1; j < n; j++){
      res = min(res, comp(l[i], l[j]));
    }
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