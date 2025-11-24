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
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  ll mx = list[max_element(list.begin(), list.end())-list.begin()];
  ll mn = list[min_element(list.begin(), list.end())-list.begin()];
  ll one=0,two=0;
  for(auto el : list){
    if(el == mn) one++;
    else if(el == mx) two++;
  }
  if(two == 0){
    cout << 0 << " " << ((one-1)*one)/2<< endl;
  } else{
    cout << mx-mn << " " << one*two << endl;
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