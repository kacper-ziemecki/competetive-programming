#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool flag=false;

void solve(ll &t){
  vector<vector<ll>> am(21, vector<ll>(21, LLONG_MAX));
  ll n,u,v;
  for(ll i = 0; i < 19; i++){
    cin >> n;
    if(cin.eof()) return;
    // dbg(n);
    for(ll j = 0; j < n; j++){
      cin >> v;
      am[i+1].at(v) = 1;
      am[v][i+1] = 1;
    }
  }

  for(ll k = 1; k <= 20; k++){
    for(ll i = 1; i <= 20; i++){
      for(ll j = 1; j <= 20; j++){
        if(am[i][k] == LLONG_MAX || am[k][j] == LLONG_MAX) continue;
        am[i][j] = min(am[i][j], am[i][k]+am[k][j]);
      }
    }
  }
  cout << "Test Set #" << t++ << endl;
  cin >> n;
  for(ll i = 0; i < n; i++){
    cin >> u >> v;
    // dbg(u,v);
    if(u < 10) cout << " ";
    cout << u << " to ";
    if(v < 10) cout << " ";
    cout << v << ": ";
    cout << am.at(u).at(v) << endl;
  }
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
  ll t=1;
  while(!cin.eof() && !flag){
    solve(t);
  }
}