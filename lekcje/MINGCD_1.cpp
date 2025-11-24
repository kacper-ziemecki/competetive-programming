#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> list(n, vector<ll>(m, 2));
  for(ll i = 0; i < min(n,m); i++) list[i][i] = 3;
  for(ll i = 0; i < abs(n-m); i++){
    if(n > m) list[i+m][0] = 3;
    else list[0][i+n] = 3;
  }
  for(auto sub : list){
    for(auto el : sub) cout << el << " ";
    cout << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}