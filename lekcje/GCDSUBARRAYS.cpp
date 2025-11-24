#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  ll n,k;
  cin >> n >> k;
  if(k < (n*(n+1))/2){ cout << -1 << endl; return; }
  k -= (n*(n+1))/2 - 1;
  cout << k << " ";
  for(ll i = 1; i < n; i++) cout << 1 << " ";
  cout << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}