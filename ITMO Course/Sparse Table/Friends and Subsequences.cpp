#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n;
const int maxn = 2e5+1, lg = log2(maxn)+1;
int a[maxn], b[maxn];
int sparse_max_a[lg][maxn], sparse_min_b[lg][maxn];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sparse_max_a[0][i] = a[i];
  }
  for(int i = 0; i < n; i++){
    cin >> b[i];
    sparse_min_b[0][i] = b[i];
  }

  for(int i = 1; i < lg; i++){
    for(int j = 0; j+(1<<i) <= n; j++){
      sparse_max_a[i][j] = max(sparse_max_a[i-1][j], sparse_max_a[i-1][j+(1<<(i-1))]);
      sparse_min_b[i][j] = min(sparse_min_b[i-1][j], sparse_min_b[i-1][j+(1<<(i-1))]);
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