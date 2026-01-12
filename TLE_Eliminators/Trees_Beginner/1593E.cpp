#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,k;
int u,v;
int cnt;
const int maxn = 4e5+1;
vector<int> adj[maxn];
int deg[maxn];

void solve(){
  cin >> n >> k;
  cnt=n;
  for(int i = 0; i <= n; i++){
    adj[i].clear();
    deg[i]=0;
  }

  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    deg[u]++;
    deg[v]++;
  }
  queue<int> q1,q2;
  for(int i = 1; i <= n; i++){
    // dbg(deg[i]);
    if(deg[i] <= 1) q1.push(i);
  }
  for(int i = 0; i < k; i++){
    if(cnt == 0) break;
    while(!q1.empty()){
      u = q1.front(); q1.pop();
      cnt--;
      deg[u] = 0;
      for(auto v : adj[u]){
        deg[v]--;
        if(deg[v] == 1) q2.push(v);
      }
    }
    // for(int i = 1; i <= n; i++) dbg(deg[i], res[i]);
    // cout << "----------------\n";
    q1 = q2;
    while(!q2.empty()) q2.pop();
  }
  cout << cnt << endl;
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

  int t;
  cin >> t;
  while(t--)
  solve();
}