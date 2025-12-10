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
  int n;
  cin >> n;
  vector<int> lista(n);
  map<int, vector<int>> mp;
  for(auto &el : lista) cin >> el;
  for(int i = 0; i < n; i++){
    // check if need to add new array
    if(mp.empty() || mp[mp.size()-1].back() >= lista[i]){
      mp[mp.size()] = {lista[i]};
      continue;
    }
    int l=0,r=mp.size()-1;
    while(l < r){
      int mid = (l+r)/2;
      if(mp[mid].back() < lista[i]) r = mid;
      else l = mid+1;
    }
    mp[l].pb(lista[i]);
  }
  for(auto el : mp){
    for(auto el1 : el.second) cout << el1 << ' ';
    cout << endl;
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