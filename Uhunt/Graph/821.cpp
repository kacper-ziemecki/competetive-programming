#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(ll u, ll v){
  ll am[101][101];
  for(ll i = 0; i < 101; i++){
    for(ll j = 0; j < 101; j++) am[i][j] = LLONG_MAX;
  }
  am[u][v]=1;
  while(cin >> u >> v, u!=0||v!=0) am[u][v]=1;

  for(ll k = 1; k < 101; k++){
    for(ll i = 1; i < 101; i++){
      for(ll j = 1; j < 101; j++){
        if(am[i][k]==LLONG_MAX||am[k][j]==LLONG_MAX) continue;
        am[i][j]=min(am[i][j], am[i][k]+am[k][j]);
      }
    }
  }
  ll cnt=0,sum=0;
  for(ll i = 1; i < 101; i++){
    for(ll j = 1; j < 101; j++){
      if(am[i][j] != LLONG_MAX && i!=j){
        sum += am[i][j]; cnt++;
        // dbg(i,j, am[i][j]);
      }
    }
  }

  cout << fixed << setprecision(3) << (ld)sum/(ld)cnt;

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
  
  ll u,v;
  ll t=1;
  while(cin >> u >> v, u!=0||v!=0){
    cout << "Case " << t++ << ": average length between pages = ";
    solve(u,v);
    cout << " clicks\n";
  }
}