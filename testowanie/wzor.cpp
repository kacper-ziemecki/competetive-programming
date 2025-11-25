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
int a[maxn], b[maxn], dist[maxn];
int sparse_max_a[lg][maxn], sparse_min_b[lg][maxn];

int get_max(int l, int r){
  int k = dist[r-l+1];
  int max_a = max(sparse_max_a[k][l], sparse_max_a[k][r-(1<<k)+1]);
  return max_a;
}
int get_min(int l, int r){
  int k = dist[r-l+1];
  int min_b = min(sparse_min_b[k][l], sparse_min_b[k][r-(1<<k)+1]);
  return min_b;
}
bool check1(int l, int srodek){
  int max_a = get_max(l, srodek);
  int min_b = get_min(l, srodek);
  // dbg(l,srodek,max_a,min_b);
  if(max_a <= min_b) return true;
  return false;
}

bool check2(int l, int srodek){
  int max_a = get_max(l, srodek);
  int min_b = get_min(l, srodek);
  if(max_a >= min_b) return true;
  return false;
}

int helper(int l, int r){
  if(l==r) return (a[l] == b[l] ? 1 : 0);

  int mid = (l+r)/2;
  int res = helper(l,mid) + helper(mid+1,r);

  for(int i = l; i <= mid; i++){
    int idxLewo,idxPrawo;
    int lewo = mid+1, prawo = r;
    while(lewo < prawo){
      int srodek = (lewo+prawo+1)/2;
      if(check1(i, srodek)) lewo = srodek;
      else prawo = srodek-1;
    }
    idxPrawo = lewo;
    lewo = mid+1, prawo = r;
    while(lewo < prawo){
      int srodek = (lewo+prawo)/2;
      if(check2(i, srodek)) prawo = srodek;
      else lewo = srodek+1;
    }
    idxLewo = prawo;
    if(get_max(i, idxLewo) == get_min(i, idxLewo)) res += idxPrawo-idxLewo+1;
    // dbg(l,mid,r, i, idxLewo, idxPrawo);
  }
  return res;
}

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

  dist[0] = dist[1] = 0;
  for(int i = 2; i <= n; i++) dist[i] = dist[i/2]+1;


  for(int i = 1; i < lg; i++){
    for(int j = 0; j+(1<<i) <= n; j++){
      sparse_max_a[i][j] = max(sparse_max_a[i-1][j], sparse_max_a[i-1][j+(1<<(i-1))]);
      sparse_min_b[i][j] = min(sparse_min_b[i-1][j], sparse_min_b[i-1][j+(1<<(i-1))]);
    }
  }
  cout << helper(0, n-1) << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}