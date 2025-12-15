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
  int n,res=0;
  cin >> n;
  vector<int> lista(n);
  for(auto &el : lista) cin >> el;
  // for(auto el : lista) cout << el << ' ';
  // cout << endl;
  
  while(!lista.empty()){
    // for(auto el : lista) cout << el << ' ';
    // cout << endl;
    int idxMax=0;
    for(int i = 0; i < lista.size(); i++){
      if(lista[i] >= lista[idxMax]) idxMax = i;
    }
    res += lista.size()-idxMax-1;
    // dbg(idxMax,res);
    lista.erase(lista.begin()+idxMax, lista.end());
  }
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

  int t;
  cin >> t;
  while(t--)
  solve();
}