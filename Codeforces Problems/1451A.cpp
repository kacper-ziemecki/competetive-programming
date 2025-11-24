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
  ll n;
  cin >> n;
  vector<ll> list;
  for(ll i = 2; i*i <= n; i++){
    if(n % i == 0){
      list.push_back(i);
      if(i != n/i) list.push_back(n/i);
    }
  }
  if(list.empty() && n >= 5){
    cout << 3 << endl;
    return;
  }
  sort(list.begin(), list.end(), greater<ll>());
  ll res = 0;
  for(ll i = 0; i < list.size(); i++){
    if((n - n/list[i]) > 1 && (n > 1)){
      n /= list[i];
      res++;
    } 
  }
  res += max(0ll, n-1);
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