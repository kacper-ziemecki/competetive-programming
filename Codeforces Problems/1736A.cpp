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
  ll n;
  cin >> n;
  vector<ll> a(n, 0ll), b(n, 0ll);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  ll sum1=0,sum2=0;
  for(auto el : a) sum1+=el;
  for(auto el : b) sum2+=el;
  bool flag = true;
  if(sum1 == sum2){
    for(ll i = 0; i < n; i++){
      if(a[i] != b[i]) flag = false;
    }
    cout << !flag << endl;
  } else if(sum1 > sum2){
    for(ll i = 0; i < n; i++){
      if(b[i] == 1 && a[i] == 0) flag = false;
    }
    cout << sum1-sum2 + !flag << endl;
  } else{
    for(ll i = 0; i < n; i++){
      if(a[i] == 1 && b[i] == 0) flag = false;
    }
    cout << sum2-sum1 + !flag << endl;
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