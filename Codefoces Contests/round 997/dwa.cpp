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
  vector<string> am(n);
  for(auto &el : am) cin >> el;
  vector<ll> adj(n,0),res(n,0);
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < i; j++){
      if(am[i][j]=='1'){
        adj[i]++;
      }
    }
  }
  for(ll i = n-1; i >= 0; i--){
    ll cnt = 0;
    for(ll j = 0; j < n; j++){
      if(res[j] == 0 && cnt == adj[i]){
        res[j] = i+1;
        break;
      } 
      if(res[j] == 0) cnt++;
    }
  }
  for(auto el : res) cout << el << " ";
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
  cin>>t;
  while(t--)
  solve();
}