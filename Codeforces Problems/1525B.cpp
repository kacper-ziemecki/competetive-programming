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
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  bool flag = true;
  for(ll i = 0; i < n; i++){
    if(list[i] != i+1){
      flag = false;
    }
  }
  if(flag){
    cout << 0 << endl;
    return;
  }
  if(list[0] == 1 || list[n-1] == n){
    cout << 1 << endl;
  }
  else if(list[0] == n && list[n-1] == 1){
    cout << 3 << endl;
  }
  else{
    cout << 2 << endl;
  }
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
  while(t--)
  solve();
  
}