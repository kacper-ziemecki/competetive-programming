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
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  map<ll,ll> mp;
  for(auto el : list) mp[el]++;
  ll before=-1, suma=0, cnt=0, res=0;
  for(auto el : mp){
    if(el.first != before+1){
      suma=0;
      cnt=0;
    }
    if(cnt == k){
      suma -= mp[el.first-k];
      cnt--;
    }
    suma += el.second;
    cnt++;
    before = el.first;
    res=max(res,suma);
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
  cin>>t;
  while(t--)
  solve();
  
} 