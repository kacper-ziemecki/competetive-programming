#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

struct Node{
  ll lo, hi, mid;
};

ll n,m,q;
const ll maxN = 1e5+1, maxQ = 1e5+1, maxM = 1e5+1;
vector<ll> mids[maxM];
pair<ll,ll> queries[maxQ], edges[maxN];
Node bin[maxQ];
ll rep[maxN], sajz[maxN];

int Find(int a){
  return (rep[a] == a ? a : rep[a] = Find(rep[a]));
}

void Union(int a, int b){
  a = Find(a);
  b = Find(b);
  if(a == b) return;
  if(sajz[a] < sajz[b]) swap(a,b);
  rep[b] = a;
  sajz[a] += sajz[b];
}

void fauclear(){
  for(int i = 1; i <= n; i++){
    sajz[i] = 1;
    rep[i] = i;
  }
}

void pharell_solve(){
  int zostalo = q;

  while(zostalo){
    fauclear();
    for(int i = 0; i <= m; i++){
      Union(edges[i].first, edges[i].second);
      for(auto z : mids[i]){
        if(Find(queries[z].first) != Find(queries[z].second)) bin[z].lo = i+1;
        else bin[z].hi = i;

        bin[z].mid = (bin[z].lo+bin[z].hi)/2;
        if(bin[z].lo == bin[z].hi) zostalo--;
        else mids[bin[z].mid].push_back(z);
      }
      mids[i].clear();
      mids[i].shrink_to_fit();
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> q;

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    edges[i] = {a, b};
  }
  
  for(int i = 1; i <= q; i++){
    int a,b;
    cin >> a >> b;
    queries[i] = {a, b};
    bin[i].lo = 0;
    bin[i].hi = m+1;
    bin[i].mid = (m+1)/2;
    mids[bin[i].mid].push_back(i)
  }
  pharell_solve();

  for(int i = 1; i <= q; i++){
    if(bin[i].lo > m) cout << "-1\n";
    else cout << bin[i].lo << "\n";
  }
}