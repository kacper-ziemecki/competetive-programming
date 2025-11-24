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
  ll n;
  cin >> n;
  n -= 2;
  vector<string> list(n, " ");
  string res;
  for(auto &el : list) cin >> el;
  ll index = -1;
  for(ll i = 1; i < n; i++){
    if(list[i][0] != list[i-1][1]){
      index = i+1;
    }
  }
  ll tmp = index;
  if(index == -1){
    cout << 'a' << list.front();
    for(ll i = 1; i < n; i++) cout << list[i][1];
    cout << endl;
  } else{
    cout << list.front();
    index -= 2;
    for(ll i = 1; i < n; i++){
      if(index == 0) cout << list[tmp-1][0];
      cout << list[i][1];
      index--;
    }
    cout << endl;
  }
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