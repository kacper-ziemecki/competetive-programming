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
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  ll g = list[0];
  for(auto el : list) g = __gcd(g, el);
  ll cnt = 0;
  ll cur = 0;
  for(auto el : list){
    cur = __gcd(cur, el);
    if(cur == g){ 
      cur = 0;
      cnt++;
    }
  }
  cout << (cnt >= k ? "YES\n" : "NO\n");
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