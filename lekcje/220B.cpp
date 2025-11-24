#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m,l,r;
const int maxN = 1e5+1, maxNs = 447;
int prefix[maxN][maxNs];
map<int,int> cnt, conversion, reverse_conversion;
int lista[maxN];

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(int i = 0; i < n; i++) cnt[lista[i]]++;
  int k = 0;
  for(auto [a,b] : cnt){
    if(b >= a){
      conversion[a] = k;
      reverse_conversion[k] = a;
      k++;
    }
  }
  if(conversion.count(lista[0])) prefix[0][conversion[lista[0]]]++;
  for(int i = 1; i < n; i++){
    for(int j = 0; j < maxNs; j++) prefix[i][j] = prefix[i-1][j];
    if(conversion.count(lista[i])) prefix[i][conversion[lista[i]]]++;
  }
  for(int i = 0; i < m; i++){
    cin >> l >> r;
    l--; r--;
    int res = 0;
    for(int j = 0; j < maxNs; j++){
      if(!reverse_conversion.count(j)) continue;
      if(l > 0 && prefix[r][j]-prefix[l-1][j] == reverse_conversion[j]){
        res++;
      } else if(l == 0 && prefix[r][j] == reverse_conversion[j]){
        res++;
      }
    }
    cout << res << endl;
  }
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}