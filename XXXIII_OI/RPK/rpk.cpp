#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const int maxN = 6;
int n,k;
int one[maxN][maxN], two[maxN][maxN];
vector<vector<int>> res;

bool check(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(one[i][j] != two[i][j]) return false;
    }
  }
  return true;
}

bool helper(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(one[i][j] != two[i][j]){
        
      }
    }
  }
  
}

void solve(){
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> one[i][j];
    }
  }
 for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> two[i][j];
    }
  }
  helper()
}
 
int main()
{

  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

} 