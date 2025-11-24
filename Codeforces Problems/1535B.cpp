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
  vector<ll> list(n, 0), one, two;
  for(auto &el : list) cin >> el;
  for(auto el : list){
    if(el & 1){
      two.push_back(el);
    }
    else{
      one.push_back(el);
    }
  }
  list.clear();
  for(auto el : one) list.push_back(el);
  for(auto el : two) list.push_back(el);

  ll res = 0;
  for(ll i = 0; i < n; i++){
    for(ll j = i+1; j < n; j++){
      if(__gcd(list[i], 2*list[j]) > 1) res++;
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

  ll t;
  cin >> t;
  while(t--)
  solve();
  
}