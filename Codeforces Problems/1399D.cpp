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
  ll n,mx=1;
  string s;
  cin >> n >> s;
  vector<ll> list(n, 1);
  priority_queue<ll, vector<ll>, greater<ll>> ones, zeros;
  if(s[0] == '1') ones.emplace(1);
  else zeros.emplace(1);

  for(ll i = 1; i < n; i++){
    if(s[i] == '0' && ones.empty()){
      mx++;
      list[i] = mx;
      zeros.emplace(mx);
    }
    else if(s[i] == '1' && zeros.empty()){
      mx++;
      list[i] = mx;
      ones.emplace(mx);
    }
    else if(s[i] == '0'){
      list[i] = ones.top();
      zeros.emplace(ones.top()); ones.pop();
    }
    else if(s[i] == '1'){
      list[i] = zeros.top();
      ones.emplace(zeros.top()); zeros.pop();
    }
  }
  cout << mx << endl;
  for(auto el : list) cout << el << " ";
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
  while(t--) solve();
}