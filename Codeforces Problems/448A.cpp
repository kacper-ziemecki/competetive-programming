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
  ll a1, a2, a3, b1, b2, b3, n;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
  ll one = a1+a2+a3, two = b1+b2+b3;
  one = (one+4)/5;
  two = (two+9)/10;
  if(one+two <= n){
    cout << "YES\n";
  } else{
    cout << "NO\n";
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

  solve();
  
} 