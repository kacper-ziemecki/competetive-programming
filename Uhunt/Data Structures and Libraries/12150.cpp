#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ll n)
{
  vector<ll> list(n, 0);
  ll a,b;
  bool res = true;
  for(ll i = 0; i < n; i++){
    cin >> a >> b;
    if(i+b < 0 || i+b >= n ||list[i+b] != 0){
      res = false;
    }
    else{
      list[i+b] = a;
    }
  }
  if(!res){
    cout << -1;
    return;
  }

  for(ll i = 0; i < n; i++){
    cout << list[i];
    if(i < n-1) cout << " ";
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
// #endif

  ll n;
  ll idx = 0;
  while(true){
    idx++;
    cin >> n;
    if(n == 0) break;
    solve(n);
    cout << endl;
  }
  
}