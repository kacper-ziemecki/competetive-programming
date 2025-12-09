#include <bits/stdc++.h>
using namespace std;
// #define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n;

int ask(int i){
  int a,b,c;
  if(i-1 == 0) a = INT_MAX;
  else{
    cout << "? " << i-1 << endl;
    cin >> a;
  }
  cout << "? " << i << endl;
  cin >> b;
  if(i+1 == n+1) c = INT_MAX;
  else{
    cout << "? " << i+1 << endl;
    cin >> c;
  }
  if(a > b && b < c) return 1; // minimum
  if(a > b && b > c) return 2; // w prawo na dul
  if(a < b && b < c) return 3; // w lewo na dul
  if(a < b && b > c) return 4; // maksimum
  cout << "zrobilem kupe" << endl;
  return -1;
}
void solve(){
  cin >> n;
  int lewo = 1, prawo = n;
  while(lewo < prawo){
    int srodek = (lewo+prawo)/2;
    int cur = ask(srodek);
    if(cur == 1){
      lewo = prawo = srodek;
    } else if(cur == 2){
      lewo = srodek+1;
    } else if(cur == 3){
      prawo = srodek-1;
    } else{
      prawo = srodek-1;
    }
  }
  for(int i = lewo; i <= prawo; i++){
    int cur = ask(i);
    if(cur == 1){
      cout << "! " << i << endl;
      return;
    }
  }
}

int main()
{

//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}