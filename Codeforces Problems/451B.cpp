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
  ll n;
  cin >> n;
  vector<ll> list1(n), list2;
  pair<ll,ll> res;
  for(auto &el : list1) cin >> el;
  list2 = list1;
  sort(list2.begin(), list2.end());
  for(ll i = 0; i < n; i++){
    if(list1[i] != list2[i]){
      res = {i, lower_bound(list2.begin(), list2.end(), list1[i])-list2.begin()};
      reverse(list1.begin()+res.first,list1.begin()+res.second+1);
      break;
    }
  }
  for(ll i = 0; i < n; i++){
    if(list1[i] != list2[i]){
      cout << "no\n";
      return;
    }
  }
  cout << "yes\n";
  cout << res.first+1 << " " << res.second+1 << endl;
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