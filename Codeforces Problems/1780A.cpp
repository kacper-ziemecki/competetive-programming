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
  vector<ll> list(n, 0);
  vector<pair<ll, ll>> a, b;
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < n; i++){
    if(list[i]&1){
      b.push_back({list[i], i});
    } else{
      a.push_back({list[i], i});
    }
  }
  if(b.size() >= 3){
    cout << "YES\n";
    cout << b[0].second+1 << " " << b[1].second+1 << " " << b[2].second+1 << endl;
  } else if(a.size()>=2 && b.size() >= 1){
    cout << "YES\n";
    ll cnt = 0;
    for(auto el : a){
      if(cnt == 2) break;
      cout << el.second+1 << " ";
      cnt++;
    }
    for(auto el : b){
      if(cnt == 3) break;
      cout << el.second+1 << " ";
      cnt++;
    }
    cout << endl;
  } else{
    cout << "NO\n";
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