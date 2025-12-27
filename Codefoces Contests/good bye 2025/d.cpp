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
  cin >> n >> m;
  vector<pair<int,int>> lista(n), res;
  for(int i = 0; i < n; i++){
    cin >> lista[i].first;
    lista[i].second = i;
  }
  sort(lista.begin(), lista.end());
  if(m > n/2){
    cout << -1 << endl;
    return;
  }
  if(m == 0){
    cout << "idk\n";
  } else{
    for(int i = 0; i < 2*(m-1); i+=2){
      res.pb(make_pair(lista[i+1].second, lista[i].second));
    }
    for(int i = 2*(m-1); i+1 < n; i++){
      res.pb(make_pair(lista[i+1].second, lista[i].second));
    }
    cout << res.size() << endl;
    for(auto sub : res){
      cout << sub.first+1 << ' ' << sub.second+1 << endl;
    }
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

  int t;
  cin >> t;
  while(t--)
  solve();
}