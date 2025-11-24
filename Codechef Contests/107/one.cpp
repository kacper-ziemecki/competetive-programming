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
  string one,two;
  cin >> one >> two;
  ll first=0,second=0;
  for(ll i = 0; i < n; i++){
    if(one[i] == two[i]){
      first++;
      second++;
    }
    if(one[i] == 'R' && two[i] == 'P') second++;
    if(one[i] == 'P' && two[i] == 'R') first++;
    if(one[i] == 'S' && two[i] == 'P') first++;
    if(one[i] == 'P' && two[i] == 'S') second++;
    if(one[i] == 'R' && two[i] == 'S') first++;
    if(one[i] == 'S' && two[i] == 'R') second++;
  }

  if(first > second) cout << 0 << endl;
  else cout << (second-first+2)/2 << endl;
}
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif
 
  ll t;
  cin >> t;
  while(t--)
  solve();
}