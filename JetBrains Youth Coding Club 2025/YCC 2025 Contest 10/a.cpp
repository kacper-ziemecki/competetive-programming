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


void solve(){
  int n,m;
  int mn1 = 10, mn2 = 10, mn3 = 10;
  cin >> n >> m;
  vector<int> lista1(n), lista2(m);
  set<int> vis;
  for(auto &el : lista1) cin >> el;
  for(auto &el : lista2) cin >> el;
  for(auto el : lista2) vis.emplace(el);
  for(auto el : lista1){
    if(vis.count(el) == 1){
      mn3 = min(mn3, el);
    }
  }
  if(mn3 != 10){
    cout << mn3 << endl;
    return;
  }
  for(auto el : lista1) mn1 = min(mn1, el);
  for(auto el : lista2) mn2 = min(mn2, el);

  if(mn1 < mn2){
    cout << mn1 << mn2 << endl;
  } else{
    cout << mn2 << mn1 << endl;
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