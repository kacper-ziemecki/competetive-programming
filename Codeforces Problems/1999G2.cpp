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

int ask(int i, int j){
  cout << "? " << i << ' ' << j << endl;
  int a; cin >> a;
  return a;
}

void solve(){
  int lewo = 2, prawo = 999;
  while(lewo < prawo){
    int srodek1 = lewo+(prawo-lewo)/3;
    int srodek2 = lewo+2*(prawo-lewo)/3;
    // dbg(lewo,prawo,srodek1,srodek2, srodek1*(srodek2+1));
    int cur = ask(srodek1,srodek2);
    if(cur == srodek1*srodek2){
      // cout << "1" << endl;
      lewo = srodek2+1;
    } else if(cur == srodek1*(srodek2+1)){
      // cout << "2" << endl;
      lewo = srodek1+1;
      prawo = srodek2;
    } else{
      // cout << "3" << endl;
      prawo = srodek1;
    }
  }
  cout << "! " << lewo << endl;
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

  int t;
  cin >> t;
  while(t--)
  solve();
}