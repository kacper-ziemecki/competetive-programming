#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p,s;

ll find_set(ll a){
  return (a==p[a] ? a : p[a] = find_set(p[a]));
}

void union_sets(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a == b) return;
  if(s[a] < s[b]) swap(a,b);
  p[b] = a;
  s[a] += s[b];
}

void solve()
{
  ll n,m,k,x,res=0;
  cin >> n >> m;
  p.assign(101, 0); s.assign(101,1);
  set<ll> list;
  for(ll i = 0; i < 101; i++) p[i]=i;
  for(ll i = 0; i < n; i++){
    cin >> k;
    if(k==0){
      res++; continue;
    }
    vector<ll> cur(k, 0);
    for(auto &el : cur) cin >> el;
    for(auto el : cur) list.emplace(el);
    for(ll i = 1; i < k; i++) union_sets(cur[i-1], cur[i]);
  }
  set<ll> st;
  for(auto el : list){
    st.emplace(find_set(el));
  }
  if(list.empty()){
    cout << res << endl;
  } else{
    cout << st.size()-1+res << endl;
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