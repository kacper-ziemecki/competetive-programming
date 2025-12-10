#include <bits/stdc++.h>
using namespace std;
// #define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  int n,k,xr=0,a;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    // dbg(xr,i);
    cout << (xr^i) << endl;
    xr ^= (xr^i);
    cin >> a;
    if(a == 1){
      return;
    }
  }
  
}

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  int t;
  cin >> t;
  while(t--)
  solve();
}