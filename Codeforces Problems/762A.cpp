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
  vector<ll> list;
  for(ll i=1; i*i <= n; i++){
    if(n%i) continue;
    list.push_back(i);
    if(i != n/i) list.push_back(n/i);
  }
  sort(list.begin(), list.end());
  if(list.size() < k){
    cout << -1 << endl;
  } else{
    cout << list[k-1] << endl;
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