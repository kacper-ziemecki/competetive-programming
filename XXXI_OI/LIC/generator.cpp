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

void solve(){
  cout << "150000 2\n";
  for(int i = 1; i <= 150000; i++) cout << i << ' ';
  cout << endl;
  for(int i = 1; i <= 150000; i++) cout << 0 << ' ';
  cout << endl;
  for(int i = 1; i <= 2; i++){
    for(int j = 1; j <= 150000; j++) cout << 30*i+(j % 17) + 1 << ' ';
    cout << endl;
  }
  
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
  freopen("../../in.in", "w", stdout);
// #endif

  solve();
}