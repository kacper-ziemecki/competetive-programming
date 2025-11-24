#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


vector<ll> lista;

ll bfs(ll x, ll n){
  vector<bool> myVis(n, false);
  queue<pair<ll, ll>> q;
  ll res = 1;
  myVis[x] = true;
  q.push({x, 1});
  while(!q.empty()){
    pair<ll, ll> tmp = q.front();
    res = max(res, tmp.second);
    q.pop();
    if(lista[tmp.first] != -1 && !myVis[lista[tmp.first]-1]){
      q.push({lista[tmp.first]-1, tmp.second+1});
      myVis[lista[tmp.first]-1] = true;
    }
  }
  return res;
}

void solve()
{
  ll n;
  cin >> n;
  lista.assign(n, 0);
  vector<bool> vis(n, false);
  ll res = 0;
  for(auto &el : lista) cin >> el;
  for(ll i = 0; i < n; i++){
    if(!vis[i]){
      res = max(res, bfs(i, n));
    }
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
#endif

  solve();
  
}