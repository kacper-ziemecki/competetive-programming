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

int n,q,x,y,t;
set<pair<int,int>> ranges;

struct DSU{
  vector<int> p,sajz;
  DSU(int n){
    p.resize(n+1);
    for(int i = 0; i <= n; i++) p[i] = i;
    sajz.assign(n+1, 1);
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
  bool in_same_set(int a, int b){
    return findSet(a) == findSet(b);
  }
};
bool in_range(int x, set<pair<int,int>>::iterator iter){
  return ((*iter).first <= x && (*iter).second >= x);
}

void solve(){
  cin >> n >> q;  
  DSU dsu(n);
  ranges.emplace(make_pair(INT_MAX, INT_MAX));
  for(int i = 0; i < q; i++){
    cin >> t >> x >> y;
    if(t == 1){
      dsu.unionSet(x,y);
    } else if(t == 2){
      int left=x,right=y;
      vector<pair<int,int>> to_erase;
      set<pair<int,int>>::iterator iter = ranges.upper_bound(make_pair(x,y));
      if(iter != ranges.begin()) iter = prev(iter);
      while(x < y || ((x == y) && in_range(x,iter))){
        while(((*iter).second < x)) iter = next(iter);
        if(in_range(x,iter)){ // to trzeba bedzie usunac
          x = (*iter).second;
          to_erase.pb(make_pair((*iter).first,(*iter).second));
          left = min(left,(*iter).first);
          right = max(right,(*iter).second);
          iter = next(iter);
        }
        if(x+1 <= y){
          x++;
          dsu.unionSet(x,x-1);
        }
      }
      for(auto el : to_erase) ranges.erase(el);
      ranges.emplace(make_pair(left,right));
    } else{
      cout << (dsu.in_same_set(x,y) ? "YES\n" : "NO\n");
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