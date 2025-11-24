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
  vector<ll> one(n), two(n);
  vector<bool> lewo1(n, false), prawo1(n, false);
  for(auto &el : one) cin >> el;
  for(auto &el : two) cin >> el;
  if(one[0] == 1) lewo1[0]=true;
  if(one[n-1] == 1) prawo1[n-1]=true;

  for(ll i = 1; i < n; i++){
    if(lewo1[i-1]) lewo1[i] = true;
    if(one[i] == 1) lewo1[i] = true;

    if(prawo1[n-i]) prawo1[n-i-1] = true;
    if(one[n-i-1] == 1) prawo1[n-i-1] = true;
  }
  // for(auto el : lewo1) cout << el << " ";
  // cout << endl;
  // for(auto el : prawo1) cout << el << " ";
  // cout << endl;

  if(one[0] != two[0] || one[n-1] != two[n-1]){
    cout << "NO\n";
    return;
  }
  for(ll i = 1; i < n-1; i++){
    if(one[i] == two[i]) continue;
    if(one[i] == 1){
      cout << "NO\n";
      return;
    }
    if(one[i] == 0 && !(lewo1[i-1] || prawo1[i+1])){
      cout << "NO\n";
      return;
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