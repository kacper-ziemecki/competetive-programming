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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll ostatnieS=-1,ostatnieP=-1;
  for(ll i = 0; i < n; i++){
    if(s[i] == 'p'){
      ostatnieP=i;
      if(ostatnieS!=-1 && ostatnieP-ostatnieS+1 < min(ostatnieP+1, n-ostatnieS)){
        cout << "NO\n"; return;
      }
    }
    else if(s[i] == 's'){
      ostatnieS=i;
      if(ostatnieP!=-1){
        cout << "NO\n"; return;
      }
    }
  }
  cout << "YES\n";
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