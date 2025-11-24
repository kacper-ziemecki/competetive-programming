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
  ll n,m;
  cin >> n >> m;
  string a,b;
  cin >> a >> b;
  for(ll i = n-2; i >= 0; i--){
    if(a[i] == a[i+1]){
      string tmp = a.substr(0, i+1);
      reverse(tmp.begin(), tmp.end());
      b += tmp;
      m = b.size();
      cout << b << endl;
      for(ll j = m-2; j >= 0; j--){
        if(b[j] == b[j+1]){
          cout << "NO\n";
          return;
        }
      }
    }
  }
  for(ll i = m-2; i >= 0; i--){
    if(b[i] == b[i+1]){
      string tmp = b.substr(0, i+1);
      reverse(tmp.begin(), tmp.end());
      a += tmp;
      n = a.size();
      cout << a << endl;
      for(ll j = n-2; j >= 0; j--){
        if(a[j] == a[j+1]){
          cout << "NO\n";
          return;
        }
      }
    }
  }
  cout << "YES\n";
 
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