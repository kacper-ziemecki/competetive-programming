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
  ll n,res=0,number=0,times=0;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  for(ll i = 1; i < n; i++){
    if(list[i-1] > list[i]){
      times = (list[i]+list[i-1]-1)/list[i];
      number = 1;
      while(number < times){
        number <<= 1;
        res++;
      }
      list[i] *= number;
    }
  }
  cout << res << endl;
}
int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}