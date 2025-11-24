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
  for(auto &el : list1) cin >> el;
  list2 = list1;
  sort(list2.begin(), list2.end());
  ll mn = list1[min_element(list1.begin(), list1.end())-list1.begin()];
  for(ll i = 0; i < n; i++){
    if(list1[i] != list2[i] && list1[i]%mn != 0){
      cout << "NO\n"; return;
    }
  }
  cout << "YES\n";
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