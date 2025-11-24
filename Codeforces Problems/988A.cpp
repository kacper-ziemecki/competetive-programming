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
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n, 0ll);
  for(auto &el : list) cin >> el;
  map<ll, ll> m;
  for(ll i = 0; i < n; i++) m[list[i]] = i+1;
  if(m.size() < k){
    cout << "NO\n";
  } else{
    cout << "YES\n";
    ll i = 0;
    for(auto el : m){
      i++;
      cout << el.second << " ";
      if(i == k){
        cout << endl;
        return;
      }
    }
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

  solve();
  
} 