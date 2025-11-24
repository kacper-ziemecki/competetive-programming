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
  ll n,k,x;
  cin >> n >> k >> x;
  if(x == 1){
    if(n == 1){
      cout << "NO\n";
      return;
    }
    if(n&1){
      if(k < 3){
        cout << "NO\n";
        return;
      }
      cout << "YES\n";
      cout << (n-3)/2+1 << endl << 3 << " ";
      for(ll i = 0; i < n/2-1; i++) cout << 2 << " ";
      cout << endl;
    } else{
      if(k < 2){
        cout << "NO\n";
        return;
      }
      cout << "YES\n";
      cout << n/2 << endl;
      for(ll i = 0; i < n/2; i++) cout << 2 << " ";
      cout << endl;
    }
  } else{
    cout <<"YES\n";
    cout << n << endl;
    for(ll i = 0; i < n; i++) cout << 1 << " ";
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