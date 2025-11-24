#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n,m;
  cin >> n;
  vector<ll> a(n, 0);
  for(auto &el : a) cin >> el;
  cin >> m;
  vector<ll> b(m, 0);
  for(auto &el : b) cin >> el;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if(a.back() > b.back()){
    cout << "Alice\nAlice\n";
  } else if(a.back() < b.back()){
    cout << "Bob\nBob\n";
  } else{
    cout << "Alice\nBob\n";
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