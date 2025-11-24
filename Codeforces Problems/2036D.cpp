#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n,m,res=0;
  cin >> n >> m;
  vector<string> list(n);
  string tmp;
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < min(n,m)/2; i++){
    tmp.clear();
    for(ll j = i; j < m-i; j++){
      tmp += list[i][j];
    }
    for(ll j = i+1; j < n-i; j++){
      tmp += list[j][m-i-1];
    }
    for(ll j = m-i-2; j >= i; j--){
      tmp += list[n-i-1][j];
    }
    for(ll j = n-i-2; j > i; j--){
      tmp += list[j][i];
    }
    for(ll j = 0; j < tmp.size(); j++){
      if(tmp[j] == '1' && tmp[(j+1)%tmp.size()] == '5' && tmp[(j+2)%tmp.size()] == '4' && tmp[(j+3)%tmp.size()] == '3') res++;
    }
  }
  cout << res << endl;
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