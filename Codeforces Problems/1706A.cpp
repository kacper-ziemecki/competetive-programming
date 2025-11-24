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
  vector<ll> list(n, 0ll);
  for(auto &el : list) cin >> el;
  map<ll, ll> mapa;
  for(auto el : list) mapa[min(el, m-el+1)]++;
  string s(m, 'B');
  for(auto el : mapa){
    if(el.second >= 2){
      s[el.first-1] = 'A';
      s[m - el.first] = 'A';
    } else{
      s[min(el.first-1, m-el.first)] = 'A';
    }
  }
  cout << s << endl;
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