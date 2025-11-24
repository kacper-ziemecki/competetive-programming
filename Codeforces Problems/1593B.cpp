#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll finding(string t, string p){
  ll j = p.size()-1;
  for(ll i = t.size() - 1; i >= 0; i--){
    if(t[i] == p[j]) j--;
    if(j < 0) return t.size() - i - p.size();
  }
  return INT_MAX;
}

void solve()
{
  string text;
  cin >> text;
  ll res = INT_MAX;
  res = min(res, finding(text, "25"));
  res = min(res, finding(text, "50"));
  res = min(res, finding(text, "75"));
  if(finding(text, "00") != text.size()-2){
    res = min(res, finding(text, "00"));
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