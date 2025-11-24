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
  ll n,a,q;
  cin >> n >> a >> q;
  ll cnt = a;
  string s;
  cin >> s;
  if(a >= n){
      cout << "YES\n";
      return;
  }
  for(auto el : s){
    if(el == '-') a--;
    else{
      a++;
      cnt++;
    }
    if(a >= n){
      cout << "YES\n";
      return;
    }
  }
  if(cnt >= n){
    cout << "MAYBE\n";
  } else{
    cout << "NO\n";
  }
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