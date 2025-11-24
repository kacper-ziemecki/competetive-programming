#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ll a, ll b)
{
  vector<ll> list(b, 0);
  for(auto &el : list) cin >> el;
  vector<ll> prefix(b, 0);
  for(ll i = 1; i < b; i++){
    prefix[i-1] = (a - list[i]) - (a - list[i-1]);
  }
  prefix[b-1] = -(a - list[b-1]);
  ll res = 0;
  for(auto el : prefix){
    if(el < 0) res += abs(el);
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
// #endif
  
  ll a,b;
  while(cin >> a >> b){
    if(a == 0 || b == 0) break;
    solve(a,b);
  }
  
}