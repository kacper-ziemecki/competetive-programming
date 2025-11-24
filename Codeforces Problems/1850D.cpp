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
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());
  ll res = 1, tmp = 1;
  for(ll i = 1; i < n; i++){
    if(list[i-1]+k >= list[i]){
      tmp++;
    }
    else{
      tmp = 1;
    }
    res = max(res, tmp);
  }
  cout << n-res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
  
}