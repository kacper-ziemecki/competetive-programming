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
  ll n;
  cin >> n;
  vector<ll> a(n, 0ll), b, c;
  for(auto &el : a) cin >> el;
  sort(a.begin(), a.end());
  if(a.front() == a.back()){
    cout << -1 << endl;
    return;
  }
  ll i = 0;
  for(;i<n && a[i]==a[0]; i++){
    b.push_back(a[i]);
  }
  for(;i < n; i++){
    c.push_back(a[i]);
  }
  cout << b.size() << " " << c.size() << endl;
  for(auto el : b) cout << el << " ";
  cout << endl;
  for(auto el : c) cout << el << " ";
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