#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ll a, ll b)
{
  vector<string> list(a, " ");
  for(auto &el : list) cin >> el;

  for(ll i = 0; i < a; i++){
    for(ll j = 0; j < b; j++){
      if(list[i][j] == '.'){
        ll cnt = 0;
        if(i > 0 && list[i-1][j] == '*') cnt++;
        if(j > 0 && list[i][j-1] == '*') cnt++;
        if(i < a-1 && list[i+1][j] == '*') cnt++;
        if(j < b-1 && list[i][j+1] == '*') cnt++;
        if(i > 0 && j > 0 && list[i-1][j-1] == '*') cnt++;
        if(i > 0 && j < b-1 && list[i-1][j+1] == '*') cnt++;
        if(i < a-1 && j > 0 && list[i+1][j-1] == '*') cnt++;
        if(i < a-1 && j < b-1 && list[i+1][j+1] == '*') cnt++;
        list[i][j] = ('0' + cnt); 
      }
    }
  }
  for(auto text : list) cout << text << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
// #endif
  
  ll a,b,t=0;
  while(true){
    t++;
    cin >> a >> b;
    if(a == 0 && b == 0) break;
    if(t > 1) cout << endl;
    cout << "Field #" << t << ":\n";
    solve(a,b);
  }
}