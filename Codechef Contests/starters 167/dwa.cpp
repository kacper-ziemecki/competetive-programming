#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  ll n,a;
  cin >> n;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  a = list[0];
  ll left = 1, right = 1000000;
  sort(list.begin(), list.end());
  for(ll i = 0; i < n; i++){
    if(list[i] == a){
      left = (i == 0 ? 1 : (list[i-1]+list[i]+1)/2);
      right = (i == n-1 ? 1000000 : (list[i]+list[i+1])/2);
      break;
    }
  }
  cout << right-left+1 << endl;
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
  while(t--)
  solve();

}