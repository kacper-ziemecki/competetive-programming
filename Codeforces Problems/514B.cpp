#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

map<pair<ll,ll>, pair<ll,ll>> p;
map<pair<ll,ll>, ll> s;

pair<ll,ll> findSet(pair<ll,ll> a){
  return (p[a] == a ? a : p[a] = findSet(p[a]));
}
void unionSet(pair<ll,ll> a, pair<ll,ll> b){
  a = findSet(a);
  b = findSet(b);
  if(a==b) return;
  if(s[a] < s[b]) swap(a, b);
  p[b] = a;
  s[a] += s[b];
}

bool check(ll x, ll y, pair<ll,ll>& a, pair<ll,ll>& b){
  if((ld)(x-a.first)/(ld)(y-a.second)+0.00001 >= (ld)(x-b.first)/(ld)(y-b.second) && (ld)(x-a.first)/(ld)(y-a.second)-0.00001 <= (ld)(x-b.first)/(ld)(y-b.second)) return true;
  return false;
}
void solve()
{
  p.clear(); s.clear();
  ll n,x,y;
  cin >> n >> x >> y;
  vector<pair<ll,ll>> list(n);
  for(auto &el : list) cin >> el.first >> el.second;
  for(auto el : list){
    p[el] = el;
    s[el] = 1;
  }
  for(ll i = 0; i < n; i++){
    for(ll j = i+1; j < n; j++){
      if(check(x,y, list[i], list[j])){
        // dbg(list[i].first, list[i].second, list[j].first, list[j].second);
        unionSet(list[i], list[j]);
      }
    }
  }
  ll res=0;
  map<pair<ll,ll>, bool> mp;
  for(auto el : list){
    if(mp.count(findSet(el))==0){
      mp[findSet(el)]=true; res++;
    }
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

  solve();  
  
} 