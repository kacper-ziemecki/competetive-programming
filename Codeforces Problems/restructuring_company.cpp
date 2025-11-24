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
vector<bool> group;

ll find_set(ll a){
  if(p[a] == a) return a;
  else if(!group[a]) return p[a] = find_set(p[a]);
  else return find_set(p[a]);
}

ll find_group_set(ll a){
  if(!group[a] || p[a] == a) return a;
  return p[a] = find_group_set(p[a]);
}

void union_two_sets(ll a, ll b){
  if(a < b) swap(a, b);
  p[b] = a;
}

void union_group_sets(ll l, ll r){
  l = find_group_set(l);
  for(ll i = l; i < r; i++){
    union_two_sets(i,r);
    group[i] = true;
  }
}

void solve()
{
  ll n,q;
  cin >> n >> q;
  ll a,b,c;

  p.assign(n+1, 0); group.assign(n+1, false);
  for(ll i = 0; i < n+1; i++) p[i]=i;

  for(ll i = 0; i < q; i++){
    cin >> a >> b >> c;
    if(a == 1){
      union_two_sets(b,c);
    } 
    else if(a == 2){
      union_group_sets(b,c);
    } 
    else{
      cout << (find_set(b) == find_set(c) ? "YES\n" : "NO\n");
    }

    // cout << "p:     ";
    // for(auto el : p) cout << el << " ";
    // cout << endl;
    // cout << "group: ";
    // for(auto el : group) cout << el << " ";
    // cout << endl;
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