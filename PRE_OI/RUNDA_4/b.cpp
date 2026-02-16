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

int n,mx_size=1;
const int N = 5e5+1;
int lista[N];
pair<int,int> ordered[N];
bool vis[N];

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
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
  }
};


void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(int i = 0; i < n; i++) ordered[i] = {lista[i],i};
  sort(ordered, ordered+n, greater<>());
  // for(int i = 0; i < n; i++){
  //   dbg(ordered[i].first, ordered[i].second);
  // }
  DSU dsu(n);
  int j = 0;
  for(int rozmiar = 1; rozmiar <= n; rozmiar++){
    while(mx_size < rozmiar){
      vis[ordered[j].second] = true;
      if(ordered[j].second-1 >= 0 && vis[ordered[j].second-1]){
        dsu.unionSet(ordered[j].second-1, ordered[j].second);
        // dbg(ordered[j].second-1, ordered[j].second);
      }
      if(ordered[j].second+1 < n && vis[ordered[j].second+1]){
        dsu.unionSet(ordered[j].second+1, ordered[j].second);
      }
      mx_size = max(mx_size, dsu.sajz[dsu.findSet(ordered[j].second)]);
      // dbg(rozmiar,j,mx_size);
      j++;
    }
    if(j > 0) cout << lista[ordered[j-1].second] << ' ';
    else cout << lista[ordered[j].second] << ' ';
  }
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