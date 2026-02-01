#include <bits/stdc++.h>
using namespace std;
// #define endl "\n"
#define pb push_back
#define ll long long
#define hs unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,k;
const int N = 1e5+1;
int F[N], S[N];
int mnF,mnS,mxF,mxS;

void solve(){
  cin >> n >> k;
  cout << "F " << 1 << endl;
  cin >> mxF;
  cout << "F " << n << endl;
  cin >> mnF;
  cout << "S " << 1 << endl;
  cin >> mxS;
  cout << "S " << n << endl;
  cin >> mnS;
  if(mnF >= mxS){
    if(k > n){
      
    } else{
      
    }
  } else if(mnS >= mxF){
    if(k > n){

    } else{
      
    }
  }
  int l = 1, r = n;
  while(l < r){

  }
}

int main()
  {

  // ios_base::sync_with_stdio(0);
  // cin.tie(0); 
  // cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}