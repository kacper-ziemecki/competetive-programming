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

int n;
int u,v;
const int N = 2e5+1;
vector<int> adj[N];
int ans[N];
pair<int,int> subtree_max[N][2];

void calc_first_ans(int u, int p){
  for(auto v : adj[u]){
    if(v != p){
      calc_first_ans(v,u);
      if(subtree_max[v][0].first+1 > subtree_max[u][0].first){
        subtree_max[u][1] = subtree_max[u][0];
        subtree_max[u][0] = make_pair(subtree_max[v][0].first+1, v);
      } else if(subtree_max[v][0].first+1 > subtree_max[u][1].first){
        subtree_max[u][1] = make_pair(subtree_max[v][0].first+1, v);
      }  
    }
  }
}
void calc_every_ans(int u, int p, int answer){
  // cout << "(" << u << " -------->:\n";
  // for(int i = 1; i <= n; i++){
  //   dbg(i);
  //   dbg(subtree_max[i][0].first, subtree_max[i][0].second);
  //   dbg(subtree_max[i][1].first, subtree_max[i][1].second);
  // }
  // cout << "--------------\n"; 
  ans[u] = answer;
  for(auto v : adj[u]){
    if(v != p){
      if(subtree_max[u][0].second != v && subtree_max[u][0].first+1 > subtree_max[v][0].first){
        subtree_max[v][1] = subtree_max[v][0];
        subtree_max[v][0] = make_pair(subtree_max[u][0].first+1, u);
      } else if(subtree_max[u][0].second != v && subtree_max[u][0].first+1 > subtree_max[v][1].first){
        subtree_max[v][1] = make_pair(subtree_max[u][0].first+1, u);
      } else if(subtree_max[u][1].second != v && subtree_max[u][1].first+1 > subtree_max[v][0].first){
        subtree_max[v][1] = subtree_max[v][0];
        subtree_max[v][0] = make_pair(subtree_max[u][1].first+1, u);
      } else if(subtree_max[u][1].second != v && subtree_max[u][1].first+1 > subtree_max[v][1].first){
        subtree_max[v][1] = make_pair(subtree_max[u][1].first+1, u);
      }
      answer = subtree_max[v][0].first;
      calc_every_ans(v,u,answer);
    }
  }
}
void solve(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  calc_first_ans(1,1);
  // for(int i = 1; i <= n; i++){
  //   dbg(i);
  //   dbg(subtree_max[i][0].first, subtree_max[i][0].second);
  //   dbg(subtree_max[i][1].first, subtree_max[i][1].second);
  // }
  // cout << "--------------\n"; 
  calc_every_ans(1,1,subtree_max[1][0].first); 
  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << endl;
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  
  solve();
}