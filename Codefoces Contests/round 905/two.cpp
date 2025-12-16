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
  ll n, k;
  cin >> n >> k;
  k = n-k;
  string text;
  cin >> text;
  map<char, ll> mapa;
  for(auto el : text) mapa[el]++;
  if(k&1){
    for(auto el : mapa){
      k -= (el.second/2)*2; 
      el.second -= (el.second/2)*2;
    }
    for(auto el : mapa){
      if(el.second > 0){
        k -= 1;
        break;
      }
    }
  } else{
    for(auto el : mapa){
      k -= (el.second/2)*2; 
      el.second -= (el.second/2)*2;
    }
  }
  if(k > 0){
    cout << "NO\n";
  } else{
    cout << "YES\n";
  }
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