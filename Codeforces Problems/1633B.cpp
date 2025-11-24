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
  string s;
  cin >> s;
  ll ones=0, zeros=0;
  for(auto el : s){
    if(el == '1') ones++;
    else zeros++;
  }
  if(zeros == 0 || ones == 0){
    cout << 0 << endl;
  }
  else if(zeros != ones){
    cout << min(zeros, ones) << endl;
  }
  else{
    ll res = 0;
    if(s[0] == '1'){
      res = max(res, min(ones-1, zeros));
    } else{
      res = max(res, min(ones, zeros-1));
    }

    if(s.back() == '1'){
      res = max(res, min(ones-1, zeros));
    } else{
      res = max(res, min(ones, zeros-1));
    }
    cout << res << endl;
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