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


bool comparator(pair<ll,ll> &a, pair<ll,ll> &b){
  if(a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

void solve(){
  ll n,group,res=0;
  cin >> n;
  vector<pair<ll,ll>> lista(n);
  for(auto &el : lista) cin >> el.first >> el.second;
  sort(lista.begin(), lista.end());
  // for(auto el : lista) cout << el.first << ',' << el.second << endl;
  // cout << endl;
  group = 1;
  for(ll i = 1; i < n; i++){
    if(lista[i].first != lista[i-1].first){
      res += (group*(group-1))/2;
      group = 0;
    }
    group++;
  }
  res += (group*(group-1))/2;
  sort(lista.begin(), lista.end(), comparator);
  // for(auto el : lista) cout << el.first << ',' << el.second << endl;
  // cout << endl;
  group = 1;
  for(ll i = 1; i < n; i++){
    if(lista[i].second != lista[i-1].second){
      res += (group*(group-1))/2;
      group = 0;
    }
    group++;
  }
  res += (group*(group-1))/2;
  group = 1;
  for(ll i = 1; i < n; i++){
    if((lista[i].second != lista[i-1].second) ||(lista[i].first != lista[i-1].first)){
      res -= (group*(group-1))/2;
      group = 0;
    }
    group++;
  }
  res -= (group*(group-1))/2;
  cout << res << endl;
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