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
  int n,suma=0,cur=0;
  cin >> n;
  vector<int> lista(n);
  for(auto &el : lista){
    cin >> el;
    suma += el;
  }
  sort(lista.begin(), lista.end(), greater<>());
  for(int i = 0; i < n; i++){
    cur += lista[i];
    if(cur*2 > suma){
      cout << i+1 << endl;
      return;
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

  solve();
}