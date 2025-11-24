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
  ll one=0,two=0,three=0;
  for(auto el : list){
    if(el%4 == 1) one++;
    if(el%4 == 2) two++;
    if(el%4 == 3) three++;
  }
  if(two&1){
    cout << -1 << endl;
    return;
  }
  ll tmp = min(one, three);
  one -= tmp;
  three -= tmp;
  if(max(one, three)%4 != 0){
    cout << -1 << endl;
  } else{
    cout << two/2 + tmp + max(one, three) - max(one, three)/4 << endl;
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

  ll t;
  cin >> t;
  while(t--)
  solve();
  
  
}