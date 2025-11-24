#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll check(ll i, ll j){
  if(i == 0 || j == 0 || i == 9 || j == 9) return 1;
  if(i == 1 || j == 1 || i == 8 || j == 8) return 2;
  if(i == 2 || j == 2 || i == 7 || j == 7) return 3;
  if(i == 3 || j == 3 || i == 6 || j == 6) return 4;
  if(i == 4 || j == 4 || i == 5 || j == 5) return 5;
}

void solve()
{
  vector<string> list(10, " ");
  ll res = 0;
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < 10; i++){
    for(ll j = 0; j < 10; j++){
      if(list[i][j] == 'X') res += check(i, j);
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
  freopen("../input.txt", "r", stdin);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
  
}