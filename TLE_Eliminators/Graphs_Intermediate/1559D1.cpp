#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define hs unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

struct DSU{
  vector<int> p,sajz;
  DSU(int n){
    p.resize(n+1);
    sajz.assign(n+1,1);
    for(int i = 0; i <= n; i++) p[i] = i;
  }
  int findSet(int a){
    return (a == p[a] ? a : p[a] = findSet(p[a]));
  }
  void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a, b);
    p[b] = a;
    sajz[a] += sajz[b];
  }
  bool connected(int a, int b){
    return findSet(a) == findSet(b);
  }
};

int n,m1,m2;
int u,v;
int res;
vector<pair<int,int>> ans;

void solve(){
  cin >> n >> m1 >> m2;
  DSU dsu1(n), dsu2(n);
  for(int i = 0; i < m1; i++){
    cin >> u >> v;
    dsu1.unionSet(u,v);
  }
  for(int i = 0; i < m2; i++){
    cin >> u >> v;
    dsu2.unionSet(u,v);
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(!dsu1.connected(j,i) && !dsu2.connected(j,i)){
        res++;
        ans.pb(make_pair(j,i));
        dsu1.unionSet(j,i);
        dsu2.unionSet(j,i);
      }
    }
  }
  cout << res << endl;
  for(auto el : ans) cout << el.first << ' ' << el.second << endl;
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

  solve();
}