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

int n,m;
int u,v;
int res=1;
int cnt=0;
const int maxn = 5e5+1;
vector<int> adj[maxn];
bool strajk[maxn];

void solve(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  } 
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> u;
    if(u > 0){
      cnt++;
      strajk[u] = true;

      int sasiedzi = adj[u].size();
      int sasiedzi_strajki = 0;
      for(auto v : adj[u]){
        if(strajk[v]) sasiedzi_strajki++;
      }
      if(sasiedzi == sasiedzi_strajki){
        res--;
      } else{
        res += max(0,sasiedzi - sasiedzi_strajki - 1);
      }
    } else{
      cnt--;
      strajk[-u] = false;
      int sasiedzi = adj[-u].size();
      int sasiedzi_strajki = 0;
      for(auto v : adj[-u]){
        if(strajk[v]) sasiedzi_strajki++;
      }
      if(sasiedzi == sasiedzi_strajki){
        res++;
      } else{
        res -= max(0, sasiedzi - sasiedzi_strajki - 1);
      }
    }

    cout << res << endl;
  }
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