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
  string s;
  cin >> s;
  map<char, ll> m;
  for(auto el : s) m[el]++;
  ll maks = 0;
  for(auto el : m) maks = max(maks, el.second);
  if(maks == 1){
    cout << 4 << endl;
  }
  if(maks == 2){
    cout << 4 << endl;
  }
  if(maks == 3){
    cout << 6 << endl;
  }
  if(maks == 4){
    cout << -1 << endl;
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