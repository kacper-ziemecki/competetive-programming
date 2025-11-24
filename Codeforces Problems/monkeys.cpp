#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p, _size, _time;
vector<bool> leader;

ll find_set(ll a){
  return (p[a] == a ? a : find_set(p[a]));
}

ll find_time(ll a){
  while(p[a] != a){
    if(_time[a] != -1) return _time[a];
    a = p[a];
  }
  return _time[a];
}

void union_sets(ll a, ll b, ll t){
  a = find_set(a);
  b = find_set(b);
  if(a == b) return;
  if(_size[a] < _size[b]) swap(a, b);
  p[b] = a;
  _size[a] += _size[b];
  if(!leader[a] && leader[b]){
    leader[a] = true;
    _time[a] = t;
  } else if(leader[a] && !leader[b]){
    leader[b] = true;
    _time[b] = t;
  }
}
void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<pair<ll,ll>> list(n), operations(m),start(n);
  for(auto &el : list) cin >> el.first >> el.second;
  for(auto &el : operations) cin >> el.first >> el.second;
  start = list;
  for(auto el : operations) {
    (el.second == 1 ? start[el.first-1].first = -1 : start[el.first-1].second = -1);
  }
  p.assign(n+1, 0); _size.assign(n+1, 1); _time.assign(n+1, -1); leader.assign(n+1, false);
  for(ll i = 0; i < n+1; i++) p[i] = i;
  leader[1] = true;
  _size[1] = n+m+1;

  for(ll i = 0; i < n; i++){
    if(start[i].first != -1) union_sets(i+1, start[i].first, -1);
    if(start[i].second != -1) union_sets(i+1, start[i].second, -1);
  }

  // cout << "leader: ";
  // for(auto el : leader) cout << el << " ";
  // cout << endl;
  // cout << "p: ";
  // for(auto el : p) cout << el << " ";
  // cout << endl;
  // cout << "_time: ";
  // for(auto el : _time) cout << el << " ";
  // cout << endl << endl;

  for(ll i = m-1; i >= 0; i--){ 
    // dbg(operations[i].first, operations[i].second, (operations[i].second == 1 ? list[operations[i].first-1].first : list[operations[i].first-1].second));
    union_sets(operations[i].first, (operations[i].second == 1 ? list[operations[i].first-1].first : list[operations[i].first-1].second), i);
    // cout << "leader: ";
    // for(auto el : leader) cout << el << " ";
    // cout << endl;
    // cout << "p: ";
    // for(auto el : p) cout << el << " ";
    // cout << endl;
    // cout << "_time: ";
    // for(auto el : _time) cout << el << " ";
    // cout << endl << endl;
  }
  for(ll i = 1; i < n+1; i++){
    cout << find_time(i) << endl;
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