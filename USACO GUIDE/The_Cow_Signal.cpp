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
  ll m,n,k;
  cin >> m >> n >> k;
  vector<string> l(m, " "), res(m*k, string(n*k, '.'));
  for(auto &el : l) cin >> el;
  for(ll i = 0; i < m; i++){
    for(ll j = 0; j < n; j++){
      if(l[i][j] == 'X'){
        for(ll x = i*k; x < i*k+k; x++){
          for(ll y = j*k; y < j*k+k; y++){
            res[x][y] = 'X';
          }
        }
      }
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
  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);
  
#endif

  solve();
}