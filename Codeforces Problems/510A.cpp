#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<string> res(n, string(m, '.'));
  for(ll i = 0; i < n; i+=2){
    res[i] = string(m, '#');
  }
  for(ll i = 1; i < n; i+=2){
    if(i%4 == 1){
      res[i][m-1] = '#';
    } else{
      res[i][0] = '#';
    }
  }
  for(auto el : res) cout << el << endl;
  
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