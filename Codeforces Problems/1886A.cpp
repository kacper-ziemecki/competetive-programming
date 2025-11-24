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
  ll n;
  cin >> n;
  if(n < 3){
    cout << "NO\n";
    return;
  }
  if(n == 12){
    cout << "YES\n1 4 7\n";
    return;
  }
  if(n%3 == 0 && n>12){
    cout << "YES\n";
    cout << n-7 << " " << 5 << " " << 2 << endl;
  } else if(n%3 != 0 && n > 3 && n != 4 && n != 5){
    cout << "YES\n";
    cout << n-3 << " " << 1 << " " << 2 << endl;
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

  ll t;
  cin >> t;
  while(t--)
  solve();
  
}