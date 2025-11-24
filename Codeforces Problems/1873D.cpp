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
  ll n,k;
  cin >> n >> k;
  string text;
  cin >> text;
  ll res = 0;
  for(ll i = 0; i < n; i++){
    if(text[i] == 'B'){
      for(ll j = i; j < min(n, i+k); j++){
        text[j] = 'W';
      }
      res++;
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
  freopen("../input.txt", "r", stdin);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
  
}