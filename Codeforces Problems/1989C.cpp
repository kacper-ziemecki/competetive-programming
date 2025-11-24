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
  ll n,one=0,two=0,minus=0,plus=0;
  cin >> n;
  vector<ll> a(n), b(n);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  for(ll i = 0; i < n; i++){
    if(a[i] > b[i]) one += a[i];
    if(b[i] > a[i]) two += b[i];
    if(a[i]==1 && b[i]==1) plus++;
    if(a[i]==-1 && b[i]==-1) minus++;
  }
  for(ll i = 0; i < plus; i++){
    if(one <= two) one++;
    else two++;
  }
  for(ll i = 0; i < minus; i++){
    if(one <= two) two--;
    else one--;
  }
  cout << min(one, two) << endl;
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