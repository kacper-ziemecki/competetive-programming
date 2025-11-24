#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p, _size, sum;

ll find_set(ll a){ 
  return (a==p[a] ? a : find_set(p[a])); 
}

void add_sum(ll a, ll x){
  a = find_set(a);
  sum[a] += x;
}

ll get_sum(ll a){
  ll res = sum[a];
  while(p[a] != a){
    a = p[a];
    res += sum[a];
  }
  return res;
}

void union_sets(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a == b) return;
  if(_size[a] < _size[b]) swap(a,b);
  p[b] = a;
  _size[a] += _size[b];
  sum[b] -= sum[a];
}

void solve()
{
  ll n,m,a,b;
  cin >> n >> m;
  string s;

  p.assign(n+1, 0); _size.assign(n+1, 1); sum.assign(n+1, 0);
  for(ll i = 0; i < n+1; i++) p[i] = i;

  for(ll i = 0; i < m; i++){
    cin >> s >> a;
    if(s == "get"){
      cout << get_sum(a) << endl;
    } else if(s == "add"){
      cin >> b;
      add_sum(a, b);
    } else{
      cin >> b;
      union_sets(a, b);
    }
    // for(auto el : p) cout << el << " ";
    // cout << endl;
    // for(auto el : sum) cout << el << " ";
    // cout << endl << endl;
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