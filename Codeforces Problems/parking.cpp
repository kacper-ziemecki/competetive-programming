#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p;

ll find_set(ll a){
  return (a == p[a] ? a : p[a] = find_set(p[a]));
}

void union_sets(ll a, ll n){
  a = find_set(a);
  p[a] = (a+1)%n;
}


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  
  p.assign(n, 0);
  for(ll i = 0; i < n; i++) p[i]=i; 

  for(auto el : list){
    cout << find_set(el-1)+1 << " ";
    union_sets(el-1, n);
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

  solve();
}