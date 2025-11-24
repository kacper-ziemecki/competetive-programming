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
  map<ll,ll>mp;
  for(auto &el : list) cin >> el;
  for(auto el : list) mp[el%10]++;
  for(ll i = 0; i <= 9; i++){
    for(ll j = 0; j <= 9; j++){
      for(ll k = 0; k <= 9; k++){
        if((i+k+j)%10 == 3){
          mp[i]--; mp[j]--; mp[k]--;
          if(mp[i] >= 0 && mp[j] >= 0 && mp[k] >= 0){
            cout << "YES\n"; return;
          }
          mp[i]++; mp[j]++; mp[k]++;
        }
      }
    }
  }
  cout << "NO\n"; 
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