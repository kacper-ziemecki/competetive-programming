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
  return (p[a] == a ? a : p[a] = find_set(p[a]));
}

void union_sets(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a == b) return;
  if(a < b) swap(a, b);
  p[b] = a;
}

void solve()
{
  ll n,m,a;
  cin >> n >> m;
  string s;

  p.assign(n+2, 0);
  for(ll i = 0; i < n+2; i++) p[i] = i;

  for(ll i = 0; i < m; i++){
    cin >> s >> a;
    if(s == "?"){
      a = find_set(a);
      cout << (a == n+1 ? -1 : a) << endl;
    } else{
      union_sets(a, a+1);
    }
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