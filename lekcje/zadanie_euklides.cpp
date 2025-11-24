#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve()
{
  ll n,mod,res=1;
  cin >> n >> mod;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < n; i++){
    for(ll j = i+1; j < n; j++)
      res = (res * __gcd(list[i], list[j])) % mod;
  }
  cout << res << endl;
}


int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}