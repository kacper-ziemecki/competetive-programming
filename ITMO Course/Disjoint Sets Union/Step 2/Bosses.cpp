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

int n,m,t,a,b,c;

struct DSU{
  vector<int> p,dist;
  DSU(int n){
    dist.assign(n+1,0);
    p.resize(n+1);
    for(int i = 0; i <= n; i++) p[i] = i;
  }
  pair<int,int> findSet(int a){
    if(a == p[a]) return make_pair(a, 0);
    else{
      pair<int,int> nxt = findSet(p[a]);
      p[a] = nxt.first;
      dist[a] += nxt.second;
      return make_pair(p[a], dist[a]);
    }
  }
  void unionSet(int a, int b){
    p[a] = b;
    dist[a] = 1;
  }
};

void solve(){
  cin >> n >> m;
  DSU dsu(n);
  for(int i = 0; i < m; i++){
    cin >> t;
    if(t==1){
      cin >> a >> b;
      dsu.unionSet(a,b);
    } else{
      cin >> c;
      cout << dsu.findSet(c).second << endl;
    }
  }
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../in.in", "r", stdin);
  freopen("../../../out.out", "w", stdout);
#endif

  solve();
}