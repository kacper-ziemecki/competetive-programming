#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll n;
  cin >> n;
  vector<vector<ll>> adj(n);
  ll u,v,m;
  for(ll i = 0; i < n; i++){
    cin >> m;
    for(ll j = 0; j < m; j++){
      cin >> v;
      adj[i].push_back(v);
    }
  }
  ll t;
  cin >> t;
  for(ll i = 0; i < t; i++){
    cin >> u;
    vector<bool> vis(n,false);
    queue<ll> q;
    vis[u]=true;
    q.push(u);
    vector<ll> res;
    while(!q.empty()){
      queue<ll> q1;
      ll cnt = 0;
      while(!q.empty()){
        q1.push(q.front());
        q.pop();
      }
      while(!q1.empty()){
        ll p = q1.front();q1.pop();
        for(ll c : adj[p]){
          if(!vis[c]){
            vis[c] = true;
            q.push(c);  
            cnt++;
          }
        }
      }
      res.push_back(cnt);
    }
    if(res[max_element(res.begin(), res.end())-res.begin()] == 0){
      cout << "0\n";continue;
    }
    cout << res[max_element(res.begin(), res.end())-res.begin()] << " " << (max_element(res.begin(), res.end())-res.begin())+1 << endl;
    // for(auto el : res) cout << el << " ";
    // cout << endl;
  }
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