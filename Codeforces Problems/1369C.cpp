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
  ll n,k,res=0;
  cin >> n >> k;
  vector<ll> a(n), b(k);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<>());
  for(ll i = k-1; i >= 0; i--){
    if(b[i] == 1) res += 2*a[n-(k-i)];
    else res += a[n-(k-i)];
  }
  ll j = 0;
  for(ll i = 0; i < k; i++){
    if(b[i] == 1) break;
    res += a[j];
    j += b[i]-1;
  }
  cout << res << endl;
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