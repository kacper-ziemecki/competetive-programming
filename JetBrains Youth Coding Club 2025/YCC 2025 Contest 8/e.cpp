#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m,k,tim=0;
const int maxn = 1e5+1;
int cords[maxn][2];
int 
void change_dir(int i, int j, int &diri, int &dirj){
  if(i == 0 || i == n){
    diri = -diri;
  }
  if(j == 0 || j == m){
    dirj = -dirj;
  }
}


void solve(){
  cin >> n >> m >> k;
  for(int i = 0; i < k; i++){
    cin >> cords[i][0] >> cords[i][1];
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