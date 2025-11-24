#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p,rang;
ll findSet(ll a){
  return (p[a] == a ? a : p[a] = findSet(p[a]));
}
void unionSet(ll a,ll b){
  a = findSet(a);
  b = findSet(b);
  if(a == b) return;
  if(rang[a] < rang[b]) swap(a, b);
  p[b] = a;
  rang[a]++;
}
void setUpDSU(ll n){
  p.assign(n+1, 0);
  rang.assign(n+1, 1);
  for(ll i = 0; i <= n; i++) p[i]=i;
}

void solve(ll t){
  ll n;
  cin >> n;
  if(cin.eof()) return;
  if(t!=0) cout << endl;
  vector<tuple<ll, ll, ll>> one(n-1);
  for(auto &el : one) cin >> get<1>(el) >> get<2>(el) >> get<0>(el);
  ll k;
  cin >> k;
  vector<tuple<ll, ll, ll>> two(k);
  for(auto &el : two) cin >> get<1>(el) >> get<2>(el) >> get<0>(el);
  ll m;
  cin >> m;
  vector<tuple<ll, ll, ll>> three(m);
  for(auto &el : three) cin >> get<1>(el) >> get<2>(el) >> get<0>(el);
  for(auto el : three) two.push_back(el);
  sort(three.begin(), three.end());
  setUpDSU(n);
  ll res1=0;
  for(auto el : three){
    if(findSet(get<1>(el)) != findSet(get<2>(el))){
      res1 += get<0>(el);
      unionSet(get<1>(el), get<2>(el));
    }
  }
  cout << res1 << endl;
  sort(two.begin(), two.end());
  setUpDSU(n);
  ll res2=0;
  for(auto el : two){
    if(findSet(get<1>(el)) != findSet(get<2>(el))){
      res2 += get<0>(el);
      unionSet(get<1>(el), get<2>(el));
    }
  }
  cout << res2 << endl;
  // for(auto el : two) cout << get<0>(el) << " " << get<1>(el) << " " << get<2>(el) << endl;
}
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  ll t=0;
  while(!cin.eof())
    solve(t++);
}