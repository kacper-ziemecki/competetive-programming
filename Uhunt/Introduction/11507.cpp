#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ll l)
{
  string tmp;
  string res = "+x";
  for(ll i = 1; i < l; i++){
    cin >> tmp;
    if(tmp == "No") continue;

    if(res == "+x"){
      res = tmp;
    }
    else if(res == "-x"){
      if(tmp[0] =='-'){
        res = "+" + string(1, tmp[1]);
      }
      else{
        res = "-" + string(1, tmp[1]);
      }
    }
    else if(res == tmp){
      res = "-x";
    }
    else if(res[1] == tmp[1] && res[0] != tmp[0]){
      res = "+x";
    }
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
// #endif
  
  ll l;
  while(true){
    cin >> l;
    if(l == 0) break;
    solve(l);
  }
}