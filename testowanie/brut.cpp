#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll n,k;
  cin >> n >> k;
  
  if(k&1){
    for(ll i = 0; i < k; i++){
      cout << n << ' ';
    }
    cout << endl;
  } else{
    ll jeden=0,dwa=0;
    for(ll i = 0; i <= n; i++){
      if(jeden+dwa < i+(n^i) && (n^i) <= n){
        jeden = i;
        dwa = n^i;
      }
    }
    // cout << jeden << ' ' << dwa << ' ';
    // for(ll i = 0; i < k-2; i++){
    //   cout << n << ' ';
    // }
    cout << jeden+dwa;
    cout << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  int t;
  cin >> t;
  while(t--)
  solve();
}