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

int n,res=1;
const int N = 1e6+1;
int lista[N];
int l,r;

bool okej(){
  int mn = INT_MAX;
  for(int i = l; i < r; i++){
    if(lista[i] > lista[r]){
      mn = min(lista[i], mn);
      if(mn < lista[i]) return false;
    }
  }
  return true;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(; r < n; r++){
    if(!okej()){
      res++;
      l = r;
    } else{
      
    }
    // dbg(i,res);
  }
  cout << res << endl;
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