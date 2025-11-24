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
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  ll numzero = 0;
  for(auto el : list) if(el == 0) numzero++;
  if(n%2 == 0){
    cout << 2 << endl;
  }
  else if(numzero == n){
    cout << 0 << endl;
  }
  else if((n - numzero)&1){
    if(numzero == 0){
      cout << 5 << endl;
      cout << 1 << " " << 2 << endl;
      cout << 1 << " " << 2 << endl;
      cout << 2 << " " << 3 << endl;
    }
    else{
      cout << 3 << endl;
      for(ll i = 1; i < n; i++){
        if((list[i] == 0 && list[i-1] != 0) || (list[i-1] == 0 && list[i] != 0)){
          cout << i << " " << i+1 << endl;
        }
      }
    }
  }
  cout << 1 << " " << n << endl;
  cout << 1 << " " << n << endl;
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