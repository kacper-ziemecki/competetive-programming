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
  ll n,i=0;
  cin >> n;
  if(n <= 2){
    cout << n << endl;
    return;
  }
  string res;
  for(ll i = 0;n > 0;i++){
    if(i&1 && n-1>=0){
      n--;
      res += '1';
    } else if(n-2 >= 0){
      n -= 2;
      res += '2';
    }
  }
  if(res[res.size()-1] == res[res.size()-2]){
    res = '1' + res.substr(0, res.size()-1);
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