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
  vector<ll> one(4, 0ll), two(4, 0ll), three(4, 0ll);
  vector<ll> pOne(4, 0ll), pTwo(4, 0ll);
  for(auto &el : one) cin >> el;
  for(auto &el : two) cin >> el;
  for(auto &el : three) cin >> el;
  ll aOne = (one[2]-one[0])*(one[1]-one[3]);
  ll aTwo = (two[2]-two[0])*(two[1]-two[3]);
  
  ll a=0,b=0;
  if(three[0] <= one[2] or three[1] <= one[3]){
    if(three[2] >= one[0] or three[3] >= one[1]){
      pOne[0] = min(three[2], one[2]);
      pOne[1] = min(three[3], one[3]);
      pOne[2] = max(three[0], one[0]);
      pOne[3] = max(three[1], one[1]);
    }
  }
  a = (pOne[2]-pOne[0])*(pOne[1]-pOne[3]);

  if(three[0] <= two[2] or three[1] <= two[3]){
    if(three[2] >= two[0] or three[3] >= two[1]){
      pTwo[0] = min(three[2], two[2]);
      pTwo[1] = min(three[3], two[3]);
      pTwo[2] = max(three[0], two[0]);
      pTwo[3] = max(three[1], two[1]);
    }
  }
  b = (pTwo[2]-pTwo[0])*(pTwo[1]-pTwo[3]);
  
  cout << aOne-a + aTwo-b << endl;
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
  while (t--) solve();
}