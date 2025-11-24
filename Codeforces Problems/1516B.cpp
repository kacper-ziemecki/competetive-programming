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
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  ll totalXor=0;
  for(auto el : list) totalXor ^= el;
  if(totalXor==0){
    cout << "YES\n";
    return;
  }
  vector<ll> xorSum(n);
  xorSum[0] = list[0];
  for(ll i = 1; i < n; i++) xorSum[i] = list[i] ^ xorSum[i-1];
  for(ll i = 0; i < n; i++){
    if(xorSum[i]==0){
      for(ll j = 0; j < i; j++){
        if(xorSum[j] == totalXor){
          cout << "YES\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
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