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
  ll n;
  cin >> n;
  vector<ll> list(n, 0ll),ans;
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());
  ll maks = list[n-1];
  ll mn = list[0];
  ll res=0;
  while(maks != mn){
    res++;
    if(maks&1 && !(mn&1)){
      maks /=2;
      mn /=2;
      ans.push_back(0);
    } else if(!(maks&1) && mn&1){
      maks = (maks+1)/2;
      mn = (mn+1)/2;
      ans.push_back(1);
    } else{
      maks /=2;
      mn /=2;
      ans.push_back(0);
    }
  }
  
  cout << res << endl;
  if(res > n || res == 0) return;
  for(auto el : ans) cout << el << " ";
  cout << endl;
}
int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while (t--) solve();
}