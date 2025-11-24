#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,q,l,r;
const int maxn = 1e6+1, lg = log2(maxn)+1;
int lista[maxn], sparse_table[lg][maxn], dif[maxn];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> lista[i];
    sparse_table[0][i] = lista[i];
  }
  dif[0] = dif[1] = 0;
  for(int i = 2; i <= n; i++){
    dif[i] = dif[i/2]+1;
  }
  for(int i = 1; i < lg; i++){
    for(int j = 0; j+(1 << i)-1 < n; j++){
      sparse_table[i][j] = min(sparse_table[i-1][j], sparse_table[i-1][j+(1<<(i-1))]);
    }
  }
  cin >> q;
  while(q--){
    cin >> l >> r;
    int k = dif[r-l+1];
    cout << min(sparse_table[k][l],sparse_table[k][r-(1<<k)+1]) << endl;
  }
} 
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  int t;
  cin >> t;
  while(t--)
  solve();
  
  
}