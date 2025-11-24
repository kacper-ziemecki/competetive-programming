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
  ll x;
  cin >> x;
  if(x > 9+8+7+6+5+4+3+2+1){
    cout << -1 << endl;
    return;
  }
  vector<int> res;
  for(ll i = 9; i > 0; i--){
    if(x-i >= 0){
      res.push_back(i);
      x-=i;
    }
  }
  reverse(res.begin(), res.end());
  for(auto el : res) cout << el;
  cout << endl;
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