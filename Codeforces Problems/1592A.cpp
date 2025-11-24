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
  ll n,h;
  cin >> n >> h;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());
  ll sum = list[n-1]+list[n-2];
  ll res = 2*(h/sum);
  h -= (h/sum) *sum;
  if(h > 0){
    h -= list[n-1];
    res++;
  }
  if(h > 0){
    h -= list[n-2];
    res++;
  }
  cout << res << endl;
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