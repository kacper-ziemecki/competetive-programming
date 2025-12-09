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
  int n;
  cin >> n;
  vector<int> lista(n), res;
  vector<bool> dp1(1000*100+1), dp2(1000*100+1);
  for(auto &el : lista) cin >> el;
  for(auto el : lista){
    dp1[0] = 1;
    for(int i = 0; i < dp1.size()-el; i++){
      if(dp1[i]) dp2[i+el] = true;
    }
    dp1 = dp2;
  }
  for(int i = 0; i < dp2.size(); i++){
    if(dp2[i]) res.pb(i);
  }
  cout << res.size() << endl;
  for(auto el : res) cout << el << ' ';
  cout << endl;
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